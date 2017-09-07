#include "LocationVector.hpp"
#include "Lens.hpp";
#include "Image.hpp";
#include "Grid.hpp";

class Camera {
  LocationVector pose_;
  LocationVector position_;
  Lens lens_;
  Image image_;
  Grid* grid_;
 public:
  Camera(LocationVector _pose, LocationVector _position, Grid* _grid);
  void setLens(double w, double h, int rw, int rh);
  void captureImage();
};
