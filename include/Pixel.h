/****************************************************************
 * Header file for the Pixel class.
 * 
 * 
 * 
 * Author/copyright: Jonathan Henly. All rights reserved.
 * Date: 12 June 2014
 * 
**/
#ifndef PIXEL_H
#define PIXEL_H

class Pixel {
  
public:
  int r;
  int g;
  int b;
  int a;
  
  Pixel();
  Pixel(int, int, int, int);

};
  
#endif // PIXEL_H
