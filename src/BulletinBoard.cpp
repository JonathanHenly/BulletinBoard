/***************************************************************
 * Main class for the BulletinBoard application.
 * 
 * Author/copyright: Jonathan Henly. All rights reserved.
 * Date: 14 June 2014
 * 
**/
#include "BulletinBoard.h"

/****************************************************************
 * Default constructor.
**/
BulletinBoard::BulletinBoard() {
  running = true;
  
  // absolute mouse position
  mAbs_x = 0; // absolute mouse x
  mAbs_y = 0; // absolute mouse y
  mAbsOld_x = 0;
  mAbsOld_y = 0;
  // absolute mouse moved boolean
  mAbsMoved = false;
  
  // initialize window booleans
  windowMaximized = false;
  windowVisible = false;
  
  // initialize key press booleans
  esc_key_down = false;
  
}

/****************************************************************
 * OnExecute() controls the flow of the uppermost processes in
 * the application.
 * 
 * Parameter(s):
 *   none
 * 
 * Returns:
 *   - an int representing something, possibly an error code...?
 * 
**/
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

/****************************************************************
 * Entry point of the compiler and application.
 * 
 * 
 * Parameter(s):
 *   argc - int representing the command line argument count
 *   argv - character array of arguments
 * 
 * Returns:
 *   - an int representing something, possibly an error code...?
 * 
**/
int main(int argc, char* argv[]) {
  BulletinBoard theBB;
  
  return theBB.OnExecute();
} // int main(int argc, char* argvp[])

