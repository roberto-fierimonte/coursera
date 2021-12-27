/**
 * C++ class for a game of the Tower of Hanoi puzzle.
 * 
 * @author
 *   Wade Fagen-Ulmschneider <waf@illinois.edu>
 */

#include "Game.h"
#include "Stack.h"
#include "uiuc/Cube.h"
#include "uiuc/HSLAPixel.h"

#include <iostream>
#include <limits>

const double infinity = std::numeric_limits<double>::max();

// Solves the Tower of Hanoi puzzle.
// (Feel free to call "helper functions" to help you solve the puzzle.)
void Game::solve() {
  // solve_recursively(4, 0, 2, 1);
  solve_iteratively();
}

void Game::solve_recursively(unsigned int n_cubes, unsigned int origin, unsigned int target, unsigned int via) {
  /* Steps:
  0. If N = 0 or N = 1, move the only cube left
  1. Move the the N-1 cubes from the origin stack to the middle stack
  2. Move the Nth cube from the origin stack to the target stack
  3. Move the N-1 cubes from the middle stack to the target stack
  */
  if (n_cubes == 1) {
    _move(origin, target);
  }
  else {
    solve_recursively(n_cubes - 1, origin, via, target);
    _move(origin, target);
    solve_recursively(n_cubes - 1, via, target, origin);
  }
}

void Game::_move(unsigned int origin, unsigned int target) {
  uiuc::Cube cube = stacks_[origin].removeTop();
  stacks_[target].push_back(cube);
  std::cout << "Moved cube of length " << cube.getLength() <<  " from stack " << (origin + 1) << " to stack " << (target + 1) << std::endl;
}

void Game::solve_iteratively() {
  /* Steps:
  While the last stack has less than N cubes on it:
    1. Move the cube of length 1 from its current position to the adjacent left (if N is odd) or right (if N is even) position
    2. Move the smallest cube of length > 1 that can make a legal move
  */
  bool solved = false;
  int smallest_origin = 0;
  int smallest_target = 0;

  bool odd_cubes = (4 % 2 == 1) ? true : false;

  while(!solved) {
    for (int i = 0; i < stacks_.size(); i++) {
      if ((stacks_[i].size() > 0) && (stacks_[i].peekTop().getLength() == 1)) {
        smallest_origin = i;
        break;
      }
    }
    
    if (odd_cubes) {
      if (smallest_origin == 0) {
        smallest_target = stacks_.size() - 1;
      }
      else {
        smallest_target = smallest_origin - 1;
      }
    }
    else {
      if (smallest_origin == stacks_.size() - 1) {
        smallest_target = 0;
      }
      else {
        smallest_target = smallest_origin + 1; 
      }
    }
    
    _move(smallest_origin, smallest_target);

    if (stacks_[2].size() < 4) {
      int next_origin = 0;
      int next_target = 0;
      double next_length = infinity;

      for (int i = 0; i < stacks_.size(); i++) {
        if ((stacks_[i].size() > 0) && (i != smallest_target) && (stacks_[i].peekTop().getLength() < next_length)) {
          next_origin = i;
          next_length = stacks_[i].peekTop().getLength();
        }
      }

      for (int j = 0; j < stacks_.size(); j++) {
        if ((j != next_origin) && (j != smallest_target)) {
          next_target = j;
        }
      }

      _move(next_origin, next_target);
    }
    else {
      solved = true;
    }
  }
}

// Default constructor to create the initial state:
Game::Game() {
  n_cubes_ = 3;
  // Create the three empty stacks:
  for (int i = 0; i < n_cubes_; i++) {
    Stack stackOfCubes;
    stacks_.push_back( stackOfCubes );
  }

  // Create the four cubes, placing each on the [0]th stack:
  uiuc::Cube blue(4, uiuc::HSLAPixel::BLUE);
  stacks_[0].push_back(blue);

  uiuc::Cube orange(3, uiuc::HSLAPixel::ORANGE);
  stacks_[0].push_back(orange);

  uiuc::Cube purple(2, uiuc::HSLAPixel::PURPLE);
  stacks_[0].push_back(purple);

  uiuc::Cube yellow(1, uiuc::HSLAPixel::YELLOW);
  stacks_[0].push_back(yellow);
}

std::ostream& operator<<(std::ostream & os, const Game & game) {
  for (unsigned i = 0; i < game.stacks_.size(); i++) {
    os << "Stack[" << i << "]: " << game.stacks_[i];
  }
  return os;
}