/****************************************************************
 * 
 * 
 * 
**/
#ifndef X_MOUSE_H
  #define X_MOUSE_H

#include <X11/Xlib.h>

class XMouse {
private:
  static Display* display;
  static Window rootWin;
  static Window retRoot;
  static Window retChild;
  static int root_x;
  static int root_y;
  static int win_x;
  static int win_y;
  static unsigned int mask;

public:
  static void getMousePos(int& x, int& y);
  
};

#endif // X_MOUSE_H
