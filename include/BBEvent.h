/****************************************************************
 * Header file for the BBEvent class.
 * 
 * 
 * 
 * Author/copyright: Jonathan Henly. All rights reserved.
 * Date: 12 June 2014
 * 
**/
#ifndef BBEVENT_H
  #define BBEVENT_H

#include "SDL2/SDL.h"

class BBEvent {

public:
  
  BBEvent();
  virtual ~BBEvent();
  
  virtual void OnEvent(SDL_Event* Event);
  
  virtual void OnKeyDown(SDL_Scancode scancode,
                         SDL_Keycode sym,
                         Uint16 mod);
  
  virtual void OnKeyUp(SDL_Scancode scancode,
                       SDL_Keycode sym,
                       Uint16 mod);
  
  virtual void OnMouseMove(Uint32 state, Sint32 x, Sint32 y,
                           Sint32 xrel, Sint32 yrel);
  
  virtual void OnLButtonDown(Sint32 x, Sint32 y);
  virtual void OnRButtonDown(Sint32 x, Sint32 y);
  virtual void OnMButtonDown(Sint32 x, Sint32 y);
  
  virtual void OnLButtonUp(Sint32 x, Sint32 y);
  virtual void OnRButtonUp(Sint32 x, Sint32 y);
  virtual void OnMButtonUp(Sint32 x, Sint32 y);
  
  virtual void OnExit();

};

#endif // BBEVENT_H
