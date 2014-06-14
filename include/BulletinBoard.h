/****************************************************************
 * Header file for the BulletinBoard class.
 * 
 * Author/copyright: Jonathan Henly. All rights reserved.
 * Date: 14 June 2014
 * 
**/
#ifndef BULLETIN_BOARD_H
  #define BULLETIN_BOARD_H

#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>

// > SDL includes
#include <SDL2/SDL.h>
// #include <SDL2/SDL_video.h>
// #include <SDL2/SDL_image.h>
// #include <SDL2/SDL_ttf.h>
// #include <SDL2/SDL_mixer.h>
// #include <SDL2/SDL2_rotozoom.h>
// #include <SDL2/SDL2_framerate.h>
// < end SDL includes

#include "BBEvent.h"
#include "Pixel.h"
#include "XMouse.h"

using namespace std;

class BulletinBoard : public BBEvent {
private:
/****************************************************************
 * Private Member Variables
**/
  bool                       running;
  SDL_DisplayMode            display;
  SDL_Window*                window;
  SDL_Renderer*              renderer;
  SDL_Texture*               texture;
  Uint32*                    pixels;
  
  // absolute mouse position
  int                        mAbs_x;
  int                        mAbs_y;
  int                        mAbsOld_x;
  int                        mAbsOld_y;
  
  // absolute mouse moved boolean
  bool                       mAbsMoved;
  
  // window booleans
  bool                       windowMaximized;
  bool                       windowVisible;
  
  // key down booleans
  bool                       esc_key_down;

/****************************************************************
 * Private Functions
**/  
/****************************************************************
 * Maximize and Minimize Window Functions
**/
  void MaximizeBullBoard(SDL_Window* window);
  void MinimizeBullBoard(SDL_Window* window);
  
  
/****************************************************************
 * End Private
**/  

public:
/****************************************************************
 * Constructors and Destructors
**/
  BulletinBoard();

/****************************************************************
 * Application Process Control Function
**/
  int OnExecute();
  
/****************************************************************
 * Top Level Process Functions
**/
  bool OnInit();  
  void OnEvent(SDL_Event* Event);
  void OnLoop();
  void OnRender();
  void OnCleanup();

/****************************************************************
 * Absolute Mouse Positioning Functions
**/
  bool MouseAbsPosChanged();
  
/****************************************************************
 * BBEvent Functions
**/
  void OnExit();
  
  // KEY DOWN
  void OnKeyDown(SDL_Scancode scancode,
                 SDL_Keycode sym,
                 Uint16 mod);
  
  // KEY UP
  void OnKeyUp(SDL_Scancode scancode,
                 SDL_Keycode sym,
                 Uint16 mod);
  
  // MOUSE MOVE
  void OnMouseMove(Uint32 state, Sint32 x, Sint32 y, Sint32 xrel,
                   Sint32 yrel);
  
  // MOUSE DOWN
  void OnLButtonDown(Sint32 x, Sint32 y);
  void OnRButtonDown(Sint32 x, Sint32 y);
  void OnMButtonDown(Sint32 x, Sint32 y);
  
  // MOUSE UP
  void OnLButtonUp(Sint32 x, Sint32 y);
  void OnRButtonUp(Sint32 x, Sint32 y);
  void OnMButtonUp(Sint32 x, Sint32 y);
  
};

#endif // BULLETIN_BOARD_H
