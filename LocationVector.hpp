#include <cmath>

class LocationVector {
public:
  double x;
  double y;
  double z;
  LocationVector(double _x, double _y, double _z) : x(_x), y(_y), z(_z) {}
  LocationVector(const LocationVector& _copy) {
    x = _copy.x;
    y = _copy.y;
    z = _copy.z;
  }
  void operator=(const LocationVector& _other) {
    x = _other.x;
    y = _other.y;
    z = _other.z;
  }
  LocationVector operator+(const LocationVector& _other) const {
    LocationVector output(*this);
    output.x += _other.x;
    output.y += _other.y;
    output.z += _other.z;
    return output;
  }
  double transformToUnitVector() {
    double magnitude = sqrt(x * x + y * y + z * z);
    double factor = 1.0 / magnitude;
    this->x *= factor;
    this->y *= factor;
    this->z *= factor;
    return magnitude;
  }
};
