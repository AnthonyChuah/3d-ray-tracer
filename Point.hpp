// Point is a POD type

class Point {
public:
  int x;
  int y;
  int z;
  int r;
  int g;
  int b;
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
