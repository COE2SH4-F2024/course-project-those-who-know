#include "GameMechs.h"

GameMechs::GameMechs()
{

    exitFlag=false; 
    loseFlag=false; 
    input=0; 
    score=0; 

    boardSizeX=35; 
    boardSizeY=15; 

   

}

GameMechs::GameMechs(int boardX, int boardY)
{
    exitFlag=false;
    loseFlag=false;
    input=0; 
    score=0; 
    
    boardSizeX=boardX;
    boardSizeY=boardY;
}

// do you need a destructor?
GameMechs::~GameMechs()
{
    
}

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
    exitFlag=true; 
}

void GameMechs::setLoseFlag()
{
    loseFlag=true;
}

void GameMechs::setInput(char this_input)
{
    input=this_input;
}

void GameMechs::clearInput()
{
    input =0; 
}

// More methods should be added here


void GameMechs::generateFood(objPos blockOff) 
{
    while (true)
    {
        int x=rand()%(getBoardSizeX()-2)+1;
        int y=rand()%(getBoardSizeY()-2)+1; 


    if (blockOff.pos->x==x && blockOff.pos->y==y)
    {
        continue;
    }

    foodPos.setObjPos(x,y,'O');
    break;

    }

}

objPos GameMechs::getFoodPos() const
{
    return foodPos; 
}