/****************************************************************
 * 
 * 
 * 
**/
#include "XMouse.h"

/****************************************************************
 * private static member variables
**/
Display* XMouse::display = XOpenDisplay(NULL);
Window XMouse::rootWin = XDefaultRootWindow(display);
Window XMouse::retRoot = NULL;
Window XMouse::retChild = NULL;
int XMouse::root_x = 0;
int XMouse::root_y = 0;
int XMouse::win_x = 0;
int XMouse::win_y = 0;
unsigned int XMouse::mask = 0;

/****************************************************************
 * Static functions
**/
void XMouse::getMousePos(int& x, int& y)
{
  
  if(XQueryPointer(XMouse::display, XMouse::rootWin,
                   &(XMouse::retRoot), &(XMouse::retChild),
                   &(XMouse::root_x), &(XMouse::root_y),
                   &(XMouse::win_x), &(XMouse::win_y),
                   &(XMouse::mask)))
  {
    x = root_x;
    y = root_y;
  }
  else
  {
    x = -1;
    y = -1;
  }
  
} // void XMouse::getMousePos(int& x, int& y)
