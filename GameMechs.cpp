#include "GameMechs.h"
#include "objPos.h"

GameMechs::GameMechs()
{

    exitFlag = false;
    loseFlag = false;
    input = 0;
    score = 0;

    boardSizeX = 35;
    boardSizeY = 15;

    foodPos = objPos();
    srand(time(NULL));
}

GameMechs::GameMechs(int boardX, int boardY)
{
 
    exitFlag = false;
    loseFlag = false;
    input = 0;
    score = 0;

    boardSizeX = boardX;
    boardSizeY = boardY;

    foodPos = objPos();
}

// do you need a destructor?
GameMechs::~GameMechs()
{
    //no destructor needed, as no memory allocs. made 
}

/*
    methods below self-explanitory 
*/
bool GameMechs::getExitFlagStatus() const
{
    return exitFlag;
}

bool GameMechs::getLoseFlagStatus() const
{
    return loseFlag;
}

char GameMechs::getInput() const
{
    return input;
}

int GameMechs::getScore() const
{
    return score;
}

void GameMechs::incrementScore()
{
    score++;
}

int GameMechs::getBoardSizeX() const
{
    return boardSizeX;
}

int GameMechs::getBoardSizeY() const
{
    return boardSizeY;
}

void GameMechs::setExitTrue()
{
    exitFlag = true;
}

void GameMechs::setLoseFlag()
{
    loseFlag = true;
}

void GameMechs::setInput(char this_input)
{
    input = this_input;
}

void GameMechs::clearInput()
{
    input = 0;
}

// More methods should be added here

void GameMechs::generateFood(objPosArrayList *blockOff)
{
    int x = 0;
    int y = 0;
    bool blocked = true; //see if position is already blocked 
    while (blocked)
    {
        blocked = false;
        x = rand() % (boardSizeX - 2) + 1;
        y = rand() % (boardSizeY - 2) + 1;
        for (int i = 0; i < blockOff->getSize(); i++) //check to see if food placement is already blocked off 
        {
            if (blockOff->getElement(i).pos->x == x && blockOff->getElement(i).pos->y == y)  //element is blocked, update the variable 
            {
                blocked = true;
                break;
            }
            
        }
    }
    foodPos = objPos(x, y, 'O'); //'O' character represents the food element 
}

objPos GameMechs::getFoodPos() const
{
    return foodPos;
}