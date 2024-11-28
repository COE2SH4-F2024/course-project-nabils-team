#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = LEFT;

    // more actions to be included

    playerPos.setObjPos(8, 6, '*');


}


Player::~Player()
{
    // delete any heap members here


}

objPos Player::getPlayerPos() const
{
    // return the reference to the playerPos arrray list
    return playerPos;

}

void Player::updatePlayerDir()
{

    char input = mainGameMechsRef->getInput();
        // PPA3 input processing logic       
    if(input != 0)  // if not null character
    {
        switch(input)
        {                      
            case ' ':  // exit
                mainGameMechsRef->setExitTrue();
                break;
            case 'W':
            case 'w':
                if (myDir == LEFT || myDir == RIGHT)
                {
                    myDir = UP;
                }
                break;
            
            case 'a':
            case 'A':
                if (myDir == UP || myDir == DOWN)
                {
                    myDir = LEFT;
                }    
                break;

            case 's':
            case 'S':
                if (myDir == LEFT || myDir == RIGHT)
                {
                    myDir = DOWN;
                }
                break;
            
            case 'd':
            case 'D':
                if (myDir == UP || myDir == DOWN)
                {
                    myDir = RIGHT;
                }
                break;

            default:
                break;
        }
        mainGameMechsRef->clearInput();
    }

}

void Player::movePlayer()
{
    // PPA3 Finite State Machine logic
    int newX = playerPos.getX();
    int newY = playerPos.getY();

    switch (myDir)
    {
    case UP:
        newY -= 1;
        break;
    case DOWN:
        newY +=1;
        break;

    case LEFT:
        newX -= 1;
        break;

    case RIGHT:
        newX += 1;
        break;

    default:
        break;
    }    
        
    if (newX < 1) newX = mainGameMechsRef->getBoardSizeX() - 2;     
    else if (newX > mainGameMechsRef->getBoardSizeX() - 2) newX = 1;    
    else if (newY < 1) newY = mainGameMechsRef->getBoardSizeY() - 2;    
    else if (newY > mainGameMechsRef->getBoardSizeY() - 2) newY = 1;

    playerPos = objPos(newX, newY, '*'); 

}

// More methods to be added