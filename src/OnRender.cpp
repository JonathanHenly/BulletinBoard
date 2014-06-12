#include "BulletinBoard.h"

void BulletinBoard::OnRender() {
  SDL_RenderClear(renderer);
  
  SDL_RenderPresent(renderer);
}
