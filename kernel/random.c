#include "random.h"

static uint32 _state = 1234567891;

void set_seed(uint32 seed) {
  _state = seed;
}

uint32 random(void) {
  _state = _state * 1664525U + 1013904223U ;
  return _state;
}
