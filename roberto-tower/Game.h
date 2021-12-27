/**
 * C++ class for a game of the Tower of Hanoi puzzle.
 * 
 * @author
 *   Wade Fagen-Ulmschneider <waf@illinois.edu>
 */

#pragma once

#include "Stack.h"
#include <vector>

class Game {
  public:
    Game();
    void solve();
    void solve_recursively(unsigned int n_cubes, unsigned int origin, unsigned int target, unsigned int via);
    void solve_iteratively();

    void _move(unsigned int origin, unsigned int target);

    // An overloaded operator<<, allowing us to print the stack via `cout<<`:
    friend std::ostream& operator<<(std::ostream & os, const Game & game);

  private:
    unsigned int n_cubes_;
    std::vector<Stack> stacks_;
};
