/**
 * Simple C++ class for representing a Cube (with constructors).
 * 
 * @author
 *   Wade Fagen-Ulmschneider <waf@illinois.edu>
 */

#include "Cube.h"
#include "HSLAPixel.h"
#include <iostream>

namespace uiuc {  
  Cube::Cube() {
    length_ = 1;
    std::cout << "Created cube of volume 1 (default)" << std::endl;
  }

  Cube::Cube(double length) {
    length_ = length;
    // std::cout << "Created cube of volume " << getVolume() << std::endl;
  }

  Cube::Cube(double length, uiuc::HSLAPixel color) {
    length_ = length;
    color_ = color;
    // std::cout << "Created cube of volume " << getVolume() << std::endl;
  }
  
  Cube::Cube(const Cube & obj) {
    length_ = obj.length_;
    // std::cout << "Copy constructor invoked on cube of volume" << getVolume() << std::endl;
  }
  
  Cube::~Cube() {
    // std::cout << "Destroyed $" << getVolume() << std::endl;
  }

  Cube & Cube::operator=(const Cube & obj) {
    // std::cout << "Transformed cube of volume" << getVolume() << "-> cube of volumne" << obj.getVolume() << std::endl;
    length_ = obj.length_;
    return *this;
  }

  double Cube::getLength() const {
    return length_;
  }

  double Cube::getVolume() const {
    return length_ * length_ * length_;
  }

  double Cube::getSurfaceArea() const {
    return 6 * length_ * length_;
  }

  void Cube::setLength(double length) {
    length_ = length;
  }
}
