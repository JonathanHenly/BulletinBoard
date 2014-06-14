#include "BBEvent.h"

BBEvent::BBEvent()
{
  // Do nothing
}

BBEvent::~BBEvent()
{
  // Do nothing
}

void BBEvent::OnEvent(SDL_Event* Event)
{
  
  switch(Event->type) {
    
    case SDL_QUIT: {
      OnExit();
      break;
    }
    
    case SDL_KEYDOWN: {
      OnKeyDown(Event->key.keysym.scancode,
                Event->key.keysym.sym,
                Event->key.keysym.mod);
      break;
    }
    
    case SDL_KEYUP: {
      OnKeyUp(Event->key.keysym.scancode, Event->key.keysym.sym,
              Event->key.keysym.mod);
      break;
    }
    
    case SDL_MOUSEMOTION: {
      OnMouseMove(Event->motion.state, Event->motion.x,
                  Event->motion.y, Event->motion.xrel,
                  Event->motion.yrel);
      break;
    }
    
    case SDL_MOUSEBUTTONDOWN: {
      switch(Event->button.button) {
        case SDL_BUTTON_LEFT: {
          OnLButtonDown(Event->button.x, Event->button.y);
        }
        case SDL_BUTTON_RIGHT: {
          OnRButtonDown(Event->button.x, Event->button.y);
        }
        case SDL_BUTTON_MIDDLE: {
          OnMButtonDown(Event->button.x, Event->button.y);
        }
      }
    }
    
    case SDL_MOUSEBUTTONUP: {
      switch(Event->button.button) {
        case SDL_BUTTON_LEFT: {
          OnLButtonUp(Event->button.x, Event->button.y);
        }
        case SDL_BUTTON_RIGHT: {
          OnRButtonUp(Event->button.x, Event->button.y);
        }
        case SDL_BUTTON_MIDDLE: {
          OnMButtonUp(Event->button.x, Event->button.y);
        }
      }
    }
    
  }
}

void BBEvent::OnKeyDown(SDL_Scancode scancode, SDL_Keycode sym,
                        Uint16 mod)
{
  // Pure virtual, do nothing
}

void BBEvent::OnKeyUp(SDL_Scancode scancode, SDL_Keycode sym,
                      Uint16 mod)
{
  // Pure virtual, do nothing
}

void BBEvent::OnMouseMove(Uint32 state, Sint32 x, Sint32 y,
                 Sint32 xrel, Sint32 yrel)
{
  // Pure virtual, do nothing
}

void BBEvent::OnLButtonDown(Sint32 x, Sint32 y)
{
  // Pure virtual, do nothing
}

void BBEvent::OnRButtonDown(Sint32 x, Sint32 y)
{
  // Pure virtual, do nothing
}

void BBEvent::OnMButtonDown(Sint32 x, Sint32 y)
{
  // Pure virtual, do nothing
}

void BBEvent::OnLButtonUp(Sint32 x, Sint32 y)
{
  // Pure virtual, do nothing
}

void BBEvent::OnRButtonUp(Sint32 x, Sint32 y)
{
  // Pure virtual, do nothing
}

void BBEvent::OnMButtonUp(Sint32 x, Sint32 y)
{
  // Pure virtual, do nothing
}

void BBEvent::OnExit()
{
  // Pure virtual, do nothing
}
