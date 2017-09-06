#include "Grid.hpp"

#include <iostream>

int main() {
  using namespace cimg_library;
  try {
    Grid<40, 40, 40> world;
    world.readPoints("test.dat");
    CImg<unsigned char> img = world.getTopDownImage();
    img.save("topdown.png");
  } catch (std::exception& e) {
    std::cout << "Some exception occurred. Please debug.\n";
    std::cout << e.what();
  }
}
