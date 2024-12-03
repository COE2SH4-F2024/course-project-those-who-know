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

    while (game->getExitFlagStatus() == false) //while exit flag is false, run the following code blocks: 
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

    exitFlag = false; //initialization of exitflag 

    game = new GameMechs(); //main instance for project use 

    player_one = new Player(game); //main player instance 

    game->generateFood(player_one->getPlayerPos());
}

void GetInput(void)
{
    if (MacUILib_hasChar())
    {
        game->setInput(MacUILib_getChar()); 
    }
}

void RunLogic(void)
{

    player_one->movePlayer();
    player_one->updatePlayerDir();
}

void DrawScreen(void)
{
    MacUILib_clearScreen();

    int x = 0; //loop variables 
    int y = 0; 

    bool exit = false;
    MacUILib_printf("Snake Game: . to exit\n");
    for (y = 0; y < (game->getBoardSizeY()); y++)
    {

        for (x = 0; x < (game->getBoardSizeX()); x++)
        {
            if (x == (game->getBoardSizeX()) - 1 || y == (game->getBoardSizeY()) - 1 || x == 0 || y == 0) 
            {
                MacUILib_printf("#"); //prints border based on the board size limits defined above 
            }
            else
            {
                bool placed = false; //variable to track if we have placed anything down 
                for (int i = 0; i < player_one->getPlayerPos()->getSize(); i++)
                {

                    int xCheck = player_one->getPlayerPos()->getElement(i).pos->x; //check for snake at x position
                    int yCheck = player_one->getPlayerPos()->getElement(i).pos->y; //check for snake at y position

                    if (x == xCheck && y == yCheck)
                    {
                        MacUILib_printf("%c", player_one->getPlayerPos()->getElement(i).getSymbol()); //prints symbol if position is clear 
                        placed = true; 
                        break;
                    }   

                    int xCheckFood = game->getFoodPos().pos->x; //check for food at x position 
                    int yCheckFood = game->getFoodPos().pos->y; //check for food at y position 

                    if (x == xCheckFood && y == yCheckFood)
                    {
                        MacUILib_printf("%c", game->getFoodPos().getSymbol()); //prints food if position is clear 
                        placed = true;
                        break;
                    }
                }
                if (placed==false)
                {
                    MacUILib_printf(" "); //prints a blank space if nothing else was placed down 
                }
            }
        }
        MacUILib_printf("\n"); 
    }
    MacUILib_printf("Score: %d\n", game->getScore()); //prints/updates score 


    if (game->getLoseFlagStatus()==true) 
        MacUILib_printf("You Lost!"); //prints losing message 
}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}

void CleanUp(void)
{
    delete player_one;
    delete game;

    MacUILib_uninit();
}
