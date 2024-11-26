#include <iostream>
#include "MacUILib.h"
#include "objPos.h"

using namespace std;

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
}

void GetInput(void)
{
    gamemechsPtr->setInput(gamemechsPtr->getInput());

}

void RunLogic(void)
{

    playerPtr->updatePlayerDir();
    playerPtr->movePlayer();
}

void DrawScreen(void)
{
    MacUILib_clearScreen();    

    for (int row = 0; row < 10; row++) {

        for (int col = 0; col < 20; col++) {

            if (row == 0 || row == 10 - 1 || col == 0 || col == 20 - 1) {

                MacUILib_printf("#");

            } else if (row == playerPtr->getPlayerPos().getY() && col == playerPtr->getPlayerPos().getX()) {
                
                 MacUILib_printf("%c", playerPtr->getPlayerPos().getSymbol());

            } else {

                MacUILib_printf(" ");

            }
            

        }
        MacUILib_printf("\n");


    }
}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{

    delete playerPtr;
    playerPtr = nullptr;
    delete gameMechsPtr;
    gameMechsPtr = nullptr;

    MacUILib_clearScreen();    

    MacUILib_uninit();

    
}
