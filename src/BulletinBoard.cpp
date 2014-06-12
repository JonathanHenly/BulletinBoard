/***************************************************************
 * Main class for the BulletinBoard application.
 * 
 * 
**/
#include "BulletinBoard.h"

BulletinBoard::BulletinBoard() {
  running = true;
}

int BulletinBoard::OnExecute() {
  if(OnInit() == false) {
    return -1;
  }
  
  SDL_Event Event;
  
  while(running) {
    while(SDL_PollEvent(&Event)) {
      OnEvent(&Event);
    }
    
    OnLoop();
    OnRender();
  }
  
  OnCleanup();
  
  return 0;
}

int main(int argc, char* argv[]) {
  BulletinBoard theBB;
  
  return theBB.OnExecute();
}

/*
int main(int argc, char* argv[]) {
  // Declare constant variables
  
  
  // Declare local variables
  SDL_Event event;
  
  
  
  // initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    return 1;
  }
  
  // initialize the private member variables 'window' and
  // 'renderer'
  SDL_CreateWindowAndRenderer(0, 0,
                                  SDL_WINDOW_FULLSCREEN_DESKTOP,
                                  &window, &renderer);
  
  // create the window where we will draw
  // window = SDL_CreateWindow("SDL_RenderClear",
  //                      SDL_WINDOWPOS_CENTERED,
  //                      SDL_WINDOWPOS_CENTERED,
  //                      512, 512,
  //                      0);
  
  // we must call SDL_CreateRenderer in order for draw calls to
  // affect this window
  // renderer = SDL_CreateRenderer(window, -1, 0);
  
  // make the scaled rendering look smoother
  SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
  SDL_RenderSetLogicalSize(renderer, 640, 480);
  
  // select the color for drawing, it is set to red here
  SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
  
  // clear the entire screen to our selected color
  SDL_RenderClear(renderer);
  
  // up until now everything was drawn behind the scenes
  // this will show the new, red contents of the window
  SDL_RenderPresent(renderer);
  
  // give us time to see the window
  // SDL_Delay(5000);
  
  // display window until quit event
  while(running) {
    SDL_WaitEvent(&event);
    
    switch(event.type) {
      case SDL_QUIT:
        running = false;
        break;
      
      case SDL_KEYDOWN:
        switch(event.key.keysym.sym) {
          // if escape key is pressed then quit program
          case SDLK_ESCAPE:
            running = false;
            break;
        }
        
        break;
    }
    
  }
  
  // always be sure to clean up
  SDL_DestroyWindow(window);
  SDL_Quit();
  return 0;

}
*/
