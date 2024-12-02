#ifndef PLAYER_H
#define PLAYER_H

#include "GameMechs.h"
#include "objPos.h"
#include "objPosArrayList.h"

class Player
{
    // Construct the remaining declaration from the project manual.

    // Only some sample members are included here

    // You will include more data members and member functions to complete your design.

    
    public:
        enum Dir {U, D, L, R, N};  // This is the direction state

        Player(GameMechs* thisGMRef);
        ~Player();

        objPosArrayList *getPlayerPos() const; // Upgrade this in iteration 3.       
        objPosArrayList *getPlayerPos() const; // Upgrade this in iteration 3.       
        void updatePlayerDir();
        void movePlayer();

        // More methods to be added here

    private:
        objPosArrayList *playerPosArrayList; // Upgrade this in iteration 3.       
        enum Dir direction;

        // Need a reference to the Main Game Mechanisms
        GameMechs* mainGameMechsRef;
};

#endif