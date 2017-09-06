// Point is a POD type

class Point {
public:
  int x;
  int y;
  int z;
  int r = 255;
  int g = 255;
  int b = 255;
  bool exists = false;
  void setData(int _x, int _y, int _z, int _r, int _g, int _b) {
    x = _x;
    y = _y;
    z = _z;
    r = _r;
    g = _g;
    b = _b;
    exists = true;
  }
};
