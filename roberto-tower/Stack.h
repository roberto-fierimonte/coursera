/**
 * C++ class for a "stack" of cubes in a Tower of Hanoi puzzle.
 * 
 * @author
 *   Wade Fagen-Ulmschneider <waf@illinois.edu>
 */

#pragma once

#include <vector>
#include "uiuc/Cube.h"

class Stack {
  public:
    void push_back(const uiuc::Cube & cube);
    uiuc::Cube removeTop();
    uiuc::Cube & peekTop();
    unsigned size() const;

    // An overloaded operator<<, allowing us to print the stack via `cout<<`:
    friend std::ostream& operator<<(std::ostream & os, const Stack & stack);

  private:
    std::vector<uiuc::Cube> cubes_;
};
