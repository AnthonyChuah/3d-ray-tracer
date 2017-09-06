#include <string>

#include "Point.hpp";

template <int X, int Y, int Z>
class Grid {
  constexpr int XLEN = X;
  constexpr int YLEN = Y;
  constexpr int ZLEN = Z;
  Point pointGrid[XLEN][YLEN][ZLEN];
  void readPoints(std::string _filename);
};

// To help visualize: imagine you are standing beside a cube and looking straight at it
// X is horizontal left/right axis
// Y is forward/backward axis
// Z is upward/downward axis
// X = 0 is leftmost
// Y = 0 is nearest to you
// Z = 0 is uppermost
