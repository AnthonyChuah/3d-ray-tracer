class Lens {
public:
  double width;
  double height;
  int resWidth; // resolution width in pixels
  int resHeight; // resolution height, e.g. 640 width 480 height
  Lens(double w, double h, int rw, int rh) : width(w), height(h), resWidth(rw), resHeight(rh) {}
  Lens(const Lens& _copy) {
    width = _copy.width;
    height = _copy.height;
    resWidth = _copy.resWidth;
    resHeight = _copy.resHeight;
  }
  void operator=(const Lens& _other) {
    width = _other.width;
    height = _other.height;
    resWidth = _other.resWidth;
    resHeight = _other.resHeight;
  }
};
