#ifndef BBEVENT_H
  #define BBEVENT_H

#include "SDL2/SDL.h"

class BBEvent {

public:
  BBEvent();
  virtual ~BBEvent();
  
  virtual void OnEvent(SDL_Event* Event);
/*  
  virtual void OnKeyDown(SDL_Keycode sym, SDL_Keymod mod);
  
  virtual void OnKeyUp(SDL_Keycode sym, SDL_Keymod mod);
*/  
  virtual void OnExit();
};

#endif
