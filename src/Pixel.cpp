#include "Pixel.h"

Pixel::Pixel() {
  this->r = 0;
  this->g = 0;
  this->b = 0;
  this->a = 0;
}

Pixel::Pixel(int red, int green, int blue, int alpha) {
  this->r = red;
  this->g = green;
  this->b = blue;
  this->a = alpha;
}

