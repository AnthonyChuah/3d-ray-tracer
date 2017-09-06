#include <iostream>
#include <fstream>

int main() {
  std::ifstream ifs;
  ifs.open("test.dat");
  int thing;
  std::cout << "Writing out all the found integers\n";
  int COLUMNS = 6;
  int x, y, z, r, g, b;
  while (true) {
    ifs >> x;
    ifs >> y;
    ifs >> z;
    ifs >> r;
    ifs >> g;
    ifs >> b;
    if (!ifs.good()) break;
    std::cout << "Calling constructor with these: " << x << " " << y << " " << z
	      << " " << r << " " << g << " " << b << "\n";
  }
  ifs.close();
}
