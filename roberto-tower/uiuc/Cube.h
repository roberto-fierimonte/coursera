/**
 * Simple C++ class for representing a Cube (with constructors).
 * 
 * @author
 *   Wade Fagen-Ulmschneider <waf@illinois.edu>
 */

#pragma once

#include "HSLAPixel.h"

namespace uiuc {
  class Cube {
    public:
      Cube();  // Custom default constructor
      Cube(double lenght);  // One argument constructor
      Cube(double length, HSLAPixel color);  // Two argument constructor
      Cube(const Cube & obj);  // Custom copy constructor
      
      ~Cube();  // Destructor

      Cube & operator=(const Cube & obj);  // Custom assignment operator

      double getLength() const;
      void setLength(double length);

      double getVolume() const;
      double getSurfaceArea() const;

    private:
      double length_;
      HSLAPixel color_;
  };
}
