#include <string>
#include <vector>
#include <fstream>
#include <exception>

#include "Point.hpp"
#include "CImg.h"

class Grid {
  static constexpr int xlen = 40;
  static constexpr int ylen = 40;
  static constexpr int zlen = 40;
  Point pointGrid[xlen][ylen][zlen];
 public:
  void readPoints(std::string _filename) {
    std::ifstream ifs;
    ifs.open(_filename);
    int x, y, z, r, g, b;
    while (true) {
      ifs >> x;
      ifs >> y;
      ifs >> z;
      ifs >> r;
      ifs >> g;
      ifs >> b;
      if (!ifs.good()) break;
      if (x < 0 || y < 0 || z < 0 || r < 0 || g < 0 || b < 0)
	throw std::runtime_error("Bad input file contains negative number.");
      if (x >= xlen || y >= ylen || z >= zlen)
	throw std::runtime_error("Bad input file contains coordinate outside Grid.");
      if (r > 255 || g > 255 || b > 255)
	throw std::runtime_error("Bad input file contains R/G/B value greater than 255.");
      pointGrid[x][y][z].setData(x, y, z, r, g, b);
    }
    ifs.close();
  }
  CImg<unsigned char> getTopDownImage() {
    using namespace cimg_library;
    CImg<unsigned char> img(xlen, ylen, 1, 3, 255);
    for (int x = 0; x < xlen; ++x) {
      for (int y = 0; y < ylen; ++y) {
	for (int z = 0; z < zlen; ++z) {
	  if (pointGrid[x][y][z].exists) {
	    img(x, y, 0) = static_cast<unsigned char>(pointGrid[x][y][z].r);
	    img(x, y, 1) = static_cast<unsigned char>(pointGrid[x][y][z].g);
	    img(x, y, 2) = static_cast<unsigned char>(pointGrid[x][y][z].b);
	    break;
	  }
	}
      }
    }
    return img;
  }
};

// To help visualize: imagine you are standing beside a cube and looking straight at it
// X is horizontal left/right axis
// Y is forward/backward axis
// Z is upward/downward axis
// X = 0 is leftmost
// Y = 0 is nearest to you
// Z = 0 is uppermost
