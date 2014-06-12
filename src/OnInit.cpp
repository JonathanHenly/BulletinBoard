#include "BulletinBoard.h"

bool BulletinBoard::OnInit() {
  if(SDL_Init(SDL_INIT_VIDEO) < 0) {
    return false;
  }
  
  SDL_CreateWindowAndRenderer(0, 0,
                                  SDL_WINDOW_FULLSCREEN_DESKTOP,
                                  &window, &renderer);
  
  SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
  SDL_RenderSetLogicalSize(renderer, 640, 480);
  
  SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
  
  SDL_RenderClear(renderer);
  
  SDL_RenderPresent(renderer);
  
  return true;
}
