#ifndef FOOD_H
#define FOOD_H

#include <cstdlib>
#include <time.h>
#include "objPos.h"
#include "objPosArrayList.h"
#include "GameMechs.h"



class Food{
    private:
        objPos foodPos;          
        GameMechs* gameMechsRef; 


    public:
        Food(GameMechs* thisGMRef); 
        ~Food();                    
        void generateFood(objPosArrayList* playerPosList); 
        objPos getFoodPos() const;


};

#endif
