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

    while (game->getExitFlagStatus() == false)
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

    player_one = new Player(game);
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

    int x = 0;
    int y = 0;

    bool exit = false;
    MacUILib_printf("Snake Game\n");
    for (y = 0; y < (game->getBoardSizeY()); y++)
    {

        for (x = 0; x < (game->getBoardSizeX()); x++)
        {
            if (x == (game->getBoardSizeX()) - 1 || y == (game->getBoardSizeY()) - 1 || x == 0 || y == 0)
            {
                MacUILib_printf("#");
            }
            else
            {
                bool placed = false;
                for (int i = 0; i < player_one->getPlayerPos()->getSize(); i++)
                {

                    int xCheck = player_one->getPlayerPos()->getElement(i).pos->x;
                    int yCheck = player_one->getPlayerPos()->getElement(i).pos->y;

                    if (x == xCheck && y == yCheck)
                    {
                        MacUILib_printf("%c", player_one->getPlayerPos()->getElement(i).getSymbol());
                        placed = true;
                        break;
                    }

                    int xCheckFood = game->getFoodPos().pos->x;
                    int yCheckFood = game->getFoodPos().pos->y;

                    if (x == xCheckFood && y == yCheckFood)
                    {
                        MacUILib_printf("%c", game->getFoodPos().getSymbol());
                        placed = true;
                        break;
                    }
                }
                if (!placed)
                {
                    MacUILib_printf(" ");
                }
            }
        }
        MacUILib_printf("\n");
    }
    MacUILib_printf("Score: %d\n", game->getScore());
    if (game->getLoseFlagStatus())
        MacUILib_printf("You Lost!");
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
