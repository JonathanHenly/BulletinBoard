#include "BulletinBoard.h"

void BulletinBoard::OnCleanup() {
  SDL_DestroyWindow(window);
  SDL_Quit();
}
