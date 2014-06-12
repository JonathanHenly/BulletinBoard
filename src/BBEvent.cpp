#include "BBEvent.h"

BBEvent::BBEvent() {
  // Do nothing
}

BBEvent::~BBEvent() {
  // Do nothing
}

void BBEvent::OnEvent(SDL_Event* Event) {
  switch(Event->type) {
    case SDL_QUIT: {
      OnExit();
      break;
    }
  }
}

void BBEvent::OnExit() {
  // Pure virtual, do nothing
}
