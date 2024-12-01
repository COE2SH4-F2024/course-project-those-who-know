#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "Player.h"
#include "GameMechs.h"


using namespace std;


Player *player_one;
GameMechs *game; 


#define DELAY_CONST 100000

bool exitFlag;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{

    Initialize();

    while(exitFlag == false)  
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();

   


}


void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();

    exitFlag = false;

    game = new GameMechs();

    player_one=new Player(game);



}

void GetInput(void)
{
    if(MacUILib_hasChar()==true)
    {
        game->setInput(MacUILib_getChar());
    }
    
   
}

void RunLogic(void)
{
    /*
    player_one=movePlayer(); 
    player_one=updatePlayerDir();
    */
    
}

void DrawScreen(void)
{
    MacUILib_clearScreen();   


    int x=0; 
    int y=0; 
    
    bool exit=false; 




    for (x=0; x<(game->getBoardSizeX()); x++)
    {
        for (y=0; y<(game->getBoardSizeY()); y++)
        {
            if (x==(game->getBoardSizeX())-1||y==(game->getBoardSizeY())-1||x==0||y==0)
            {
                MacUILib_printf("#");
                continue;
            }

            
        }
    }
}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    

    MacUILib_uninit();
}
