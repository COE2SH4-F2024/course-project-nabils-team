#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "Player.h"
#include "GameMechs.h"


using namespace std;

#define DELAY_CONST 100000

bool exitFlag;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);

Player* playerPtr = nullptr; 
GameMechs* gameMechsPtr = nullptr; 



int main(void)
{

    Initialize();

    while(gameMechsPtr->getExitFlagStatus() == false)  
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
     
    gameMechsPtr = new GameMechs();

    extern GameMechs* gameMechsPtr; 

    playerPtr = new Player(gameMechsPtr);
    

}

void GetInput(void)
{
    
    gameMechsPtr->setInput(gameMechsPtr->getInput());
}

void RunLogic(void)
{

    playerPtr->updatePlayerDir();
    playerPtr->movePlayer();
}

void DrawScreen(void)
{
    MacUILib_clearScreen();    

    

    for (int row = 0; row < gameMechsPtr->getBoardSizeY(); row++) {

        for (int col = 0; col < gameMechsPtr->getBoardSizeX(); col++) {

            if (row == 0 || row == gameMechsPtr->getBoardSizeY() - 1 || col == 0 || col == gameMechsPtr->getBoardSizeX() - 1) {

                MacUILib_printf("#");

            } 
            else 
            {

                bool snakebodypart = false; 
                for (int i =0; i<playerPtr->getPlayerPos()->getSize(); i++) 
                {
                    if (row == playerPtr->getPlayerPos()->getElement(i).getY() && col == playerPtr->getPlayerPos()->getElement(i).getX())
                    {
                    MacUILib_printf("%c", playerPtr->getPlayerPos()->getHeadElement().getSymbol());
                    snakebodypart = true;
                    break;
                    }
                }
                if(snakebodypart == false)
                {
                    MacUILib_printf(" ");

                }
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