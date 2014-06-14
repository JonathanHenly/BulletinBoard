/****************************************************************
 * 
 * 
 * 
**/
#include "BulletinBoard.h"

void BulletinBoard::OnRender() {
  
  if(windowVisible) {
    SDL_UpdateTexture(texture, NULL, pixels, display.w * sizeof(Uint32));
    
    // clear the window
    SDL_RenderClear(renderer);
    
    // copy texture to window
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    
    // refresh the window
    SDL_RenderPresent(renderer);
  }
  
}
