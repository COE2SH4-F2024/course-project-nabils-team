#include "MacUILib.h"
#include "Food.h"
#include <cstdlib> 
#include <ctime>   
#include "Player.h"
#include "objPos.h"
#include "objPosArrayList.h"
#include "GameMechs.h"



Food::Food(GameMechs* thisGMRef):gameMechsRef(thisGMRef) 
{
    srand(static_cast<unsigned>(time(0))); 
    generateFood(objPos(0, 0, '*'));       
}

Food::~Food() {

}

void Food::generateFood(objPos playerPos) {
    int boardX = gameMechsRef->getBoardSizeX();
    int boardY = gameMechsRef->getBoardSizeY();

    int newX, newY;
    do {
        newX = rand() % boardX; 
        newY = rand() % boardY; 
    } while (newX == playerPos.getX()  && newY == playerPos.getY());

    gameMechsRef->newFood = false;


    foodPos = objPos(newX, newY, 'O'); 
}

objPos Food::getFoodPos() const {
    return foodPos;
}
