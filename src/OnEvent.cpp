/****************************************************************
 * 
 * 
 * 
**/
#include "BulletinBoard.h"

void BulletinBoard::OnEvent(SDL_Event* Event) {
  BBEvent::OnEvent(Event);
}

void BulletinBoard::OnExit() {
  running = false;
}

void BulletinBoard::OnKeyDown(SDL_Scancode scancode,
                              SDL_Keycode sym,
                              Uint16 mod)
{ 
  if(sym == SDLK_ESCAPE) {
    esc_key_down = true;
  }
  
}

void BulletinBoard::OnKeyUp(SDL_Scancode scancode,
                              SDL_Keycode sym,
                              Uint16 mod)
{
  if(sym == SDLK_ESCAPE) {
    esc_key_down = false;
  }
  
}

void BulletinBoard::OnMouseMove(Uint32 state, Sint32 x, Sint32 y,
                                Sint32 xrel, Sint32 yrel)
{
  
  /*
  std::cout << "x: " << x << " xrel: " << xrel
            << "\ny: " << y << " yrel: " << yrel << "\n";
  */

}

void BulletinBoard::OnLButtonDown(Sint32 x, Sint32 y)
{
  
}

void BulletinBoard::OnRButtonDown(Sint32 x, Sint32 y)
{
  
}

void BulletinBoard::OnMButtonDown(Sint32 x, Sint32 y)
{
  
}

void BulletinBoard::OnLButtonUp(Sint32 x, Sint32 y)
{

}

void BulletinBoard::OnRButtonUp(Sint32 x, Sint32 y)
{

}

void BulletinBoard::OnMButtonUp(Sint32 x, Sint32 y)
{

}
