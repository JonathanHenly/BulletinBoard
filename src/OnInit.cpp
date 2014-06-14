/****************************************************************
 * 
 * 
 *
**/
#include "BulletinBoard.h"

bool BulletinBoard::OnInit() {
  
  if(SDL_Init(SDL_INIT_VIDEO) < 0) {
    return false;
  }
  
  for(int i = 0; i < SDL_GetNumVideoDisplays(); ++i) {
    int shouldBeZero = SDL_GetCurrentDisplayMode(i, &display);
    
    if(shouldBeZero != 0) {
      cout << "Could not get display mode for video display" 
         << i << ": " << SDL_GetError();
    }
  }
   
  window = SDL_CreateWindow("BulletinBoard",
                            SDL_WINDOWPOS_UNDEFINED,
                            SDL_WINDOWPOS_UNDEFINED,
                            display.w,
                            display.h,
                            SDL_WINDOW_FULLSCREEN_DESKTOP);
  
  renderer = SDL_CreateRenderer(window, -1, 
                                SDL_RENDERER_ACCELERATED);
  
  texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888,
                              SDL_TEXTUREACCESS_STREAMING,
                              display.w, display.h);
  
  SDL_MinimizeWindow(window);
  
  SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
  SDL_RenderSetLogicalSize(renderer, display.w, display.h);
  
  // SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
  
  pixels = new Uint32[display.w * display.h];
  memset(pixels, 255, display.w * display.h * sizeof(Uint32));
  
  // clear the window
  SDL_RenderClear(renderer);
  
  // refresh the window
  SDL_RenderPresent(renderer);
  
  // cout << "\nOnInit Error: " << SDL_GetError() << "\n";
  
  return true;
}
