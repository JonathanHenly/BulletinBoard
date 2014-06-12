#ifndef BULLETIN_BOARD_H
  #define BULLETIN_BOARD_H

#include <iostream>
#include <cstdlib>

#include "SDL2/SDL.h"
#include "Pixel.h"

#include "BBEvent.h"

class BulletinBoard : public BBEvent {
private:
  bool           running;
  SDL_Window*    window;
  SDL_Renderer*  renderer;
  
public:
  BulletinBoard();
  int OnExecute();
  
  bool OnInit();
  void OnEvent(SDL_Event* Event);
  void OnLoop();
  void OnRender();
  void OnCleanup();
  
  // BBEvent functions
  void OnExit();
};

#endif
