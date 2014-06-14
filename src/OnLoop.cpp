/****************************************************************
 * BulletinBoard's 'OnLoop' process. 
 * 
 * Author/copyright: Jonathan Henly. All rights reserved.
 * Date: 14 June 2014
 * 
**/
#include "BulletinBoard.h"

/****************************************************************
 * Function to maximize a window and update some booleans.
 * 
 * Parameter(s):
 *   window - as SDL_Window object that will be maximized
 * 
 * Returns:
 *   - none
 * 
**/
void BulletinBoard::MaximizeBullBoard(SDL_Window* window)
{
  SDL_MaximizeWindow(window);
  
  windowMaximized = true;
  windowVisible = true;
} // void BulletinBoard::MaximizeBullBoard(SDL_Window* window)

/****************************************************************
 * Function to minimize a window and update some booleans.
 * 
 * Parameter(s):
 *   window - as SDL_Window object that will be minimized
 * 
 * Returns:
 *   - none
 * 
**/
void BulletinBoard::MinimizeBullBoard(SDL_Window* window)
{
  SDL_MinimizeWindow(window);
  
  windowMaximized = false;
  windowVisible = false;
} // void BulletinBoard::MaximizeBullBoard(SDL_Window* window)

/****************************************************************
 * Function that updates the absolute position of the mouse's x
 * and y values, and returns a boolean based on a change in
 * either the x or y value.
 * 
 * Parameter(s):
 *   none
 * 
 * Returns:
 *   - true if there has been a change in either the x or y
 * 
**/
bool BulletinBoard::MouseAbsPosChanged()
{
  XMouse::getMousePos(mAbs_x, mAbs_y);
  
  if((mAbsOld_x != mAbs_x) || (mAbsOld_y != mAbs_y)) {
    mAbsOld_x = mAbs_x;
    mAbsOld_y = mAbs_y;
    
    return true;
  }
  
  return false;
} // bool BulletinBoard::MouseAbsPosChanged()

/****************************************************************
 * BulletinBoard's main logical loop handler.
 * 
 * Parameter(s):
 *   none
 * 
 * Returns:
 *   - none
 * 
**/
void BulletinBoard::OnLoop()
{
  
  mAbsMoved = MouseAbsPosChanged();
  
  if((mAbs_x == 0) && (mAbs_y >= (display.h - 1)) && (mAbsMoved))
  {
    if(windowMaximized) {
      cout << "Mouse: On  - " << windowMaximized << "\n";
      MinimizeBullBoard(window);
    }
    else if(!windowMaximized)
    {
      cout << "Mouse: Off - " << windowMaximized << "\n";
      MaximizeBullBoard(window);
    }
  }
  
  /*
  if((mAbs_x == 0) && 
     (mAbs_y >= (display.h - 4)) &&
     !(windowMaximized) && 
     ( mAbsMoved ))
  {
    windowMaximized = true;
    
    
    SDL_MaximizeWindow(window);
    windowVisible = true;
  }
  else if((mAbs_x == 0) && 
          (mAbs_y >= display.h - 4) &&
          (windowMaximized) && 
          ( mAbsMoved))
  {
    SDL_MinimizeWindow(window);
    windowMaximized = false;
    windowVisible = false;
  }
  */
  
  if(esc_key_down && windowMaximized)
  {
    SDL_MinimizeWindow(window);
    windowMaximized = false;
    windowVisible = false;
  }
  
  // mAbsOld_x = mAbs_x;
  // mAbsOld_y = mAbs_y;
  
} // void BulletinBoard::OnLoop()
