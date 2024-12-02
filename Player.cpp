#include "Player.h"

Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    direction = N;

    // more actions to be included

    playerPosArrayList = new objPosArrayList();
    playerPosArrayList->insertHead(objPos(mainGameMechsRef->getBoardSizeX() / 2, mainGameMechsRef->getBoardSizeY() / 2, '*'));
}


Player::~Player()
{
    delete playerPosArrayList;
}

objPosArrayList *Player::getPlayerPos() const
{
    return playerPosArrayList;
}

void Player::updatePlayerDir()
{
    // PPA3 input processing logic  
    char inp = mainGameMechsRef->getInput();
    if (!inp) // if not null character
    {
        switch (inp)
        {
        case '.': // exit
            mainGameMechsRef->setExitTrue();
            break;
        case 'w':
            if (direction == L || direction == R || direction == N)
            {
                direction = U;
            }
            break;
        case 's':
            if (direction == L || direction == R || direction == N)
            {
                direction = D;
            }
            break;
        case 'd':
            if (direction == U || direction == D || direction == N)
            {
                direction = R;
            }
            break;
        case 'a':
            if (direction == U || direction == D || direction == N)
            {
                direction = L;
            }
            break;
        default:
            break;
        }
    }        
}

void Player::movePlayer()
{
        // PPA3 Finite State Machine logic
    objPos newHead = (playerPosArrayList->getHeadElement());
    int eaten_food = 0;
    if (direction == U || direction == D) {
        // Moving vertically
        int newY;
        if (direction == U) {
            newY = newHead.pos->y - 1;
        } else {
            newY = newHead.pos->y + 1;
        }
        // Wraparound logic for vertical movement
        if (newY == 0) {
            newY = mainGameMechsRef->getBoardSizeY() - 2;
        } else if (newY == mainGameMechsRef->getBoardSizeY() - 1) {
            newY = 1;
        }
        newHead = objPos(newHead.pos->x, newY, '*');
    } else if (direction == L || direction == R) {
        // Moving horizontally
        int newX;
        if (direction == L) {
            newX = newHead.pos->x - 1;
        } else {
            newX = newHead.pos->x + 1;
        }
        // Wraparound logic for horizontal movement
        if (newX == 0) {
            newX = mainGameMechsRef->getBoardSizeX() - 2;
        } else if (newX == mainGameMechsRef->getBoardSizeX() - 1) {
            newX = 1;
        }
        newHead = objPos(newX, newHead.pos->y, '*');
    }

    if (direction != N){
        playerPosArrayList->insertHead(newHead); // insert at head at new position
        for (int i = 1; i <= playerPosArrayList->getSize() - 1; i++)
            {
                if (newHead.pos->x == playerPosArrayList->getElement(i).pos->x && newHead.pos->y == playerPosArrayList->getElement(i).pos->y) // if collision with body, exit and lose
                {
                    mainGameMechsRef->setExitTrue();
                    mainGameMechsRef->setLoseFlag();
                }
            }
        if (!eaten_food)
        playerPosArrayList->removeTail(); // keeps snake body length constant if no food
    }
}

// More methods to be added
