#include <iostream>
#include "src/Game.h"

int main( ) {
   //Init Game Engine
   
   
   //Init time
   std::srand(static_cast<unsigned>(time(NULL)));
   Game game;
   //Game Loop
   // && !game.getEndGame() - use this to instantl;y colse the window 
   while (game.running()  && !game.getEndGame())
   {
    //event polling gonna be inside the game itself
   
    //Update
    game.update();
    //Render
    game.render();
   }
    //End of application
    return 0;
    
}

