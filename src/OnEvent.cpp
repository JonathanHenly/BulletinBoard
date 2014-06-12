#include "BulletinBoard.h"

void BulletinBoard::OnEvent(SDL_Event* Event) {
  BBEvent::OnEvent(Event);
}

void BulletinBoard::OnExit() {
  running = false;
}

/*
void BulletinBoard::OnKeyDown(SDL_Keycode sym, SDL_Keymod mod)
{
  
}

void BulletinBoard::OnKeyUp(SDL_Keycode sym, SDL_Keymod mod)
{
  
}
*/
