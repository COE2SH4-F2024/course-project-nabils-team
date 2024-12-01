#include "MacUILib.h"
#include "Food.h"
#include <cstdlib> 
#include <ctime>   

Food::Food(GameMechs* thisGMRef)
    : gameMechsRef(thisGMRef), foodPos(0, 0, 'O') { // Initialize food position with a default value
    srand(static_cast<unsigned>(time(0))); // Seed the random number generator
    generateFood(objPos(0, 0, '*'));       // Generate the first food item
}

Food::~Food() {
    // Nothing to clean up as no dynamic memory is allocated
}

void Food::generateFood(objPos playerPos) {
    int boardX = gameMechsRef->getBoardSizeX();
    int boardY = gameMechsRef->getBoardSizeY();

    int newX, newY;
    do {
        newX = rand() % boardX; // Random x-coordinate
        newY = rand() % boardY; // Random y-coordinate
    } while (newX == playerPos.getX() && newY == playerPos.getY()); // Avoid player's position

    foodPos = objPos(newX, newY, 'O'); // Set new food position
}

objPos Food::getFoodPos() const {
    return foodPos;
}
