#ifndef JEU_H
#define JEU_H

#include "Personnage.h"
#include "terrain.h"



class Jeu{
    private:



    public:
    

    Personnage MP;
    Personnage SP;
    terrain ter1;

    void actionsAutomatique(float deltaTime);
    void actionsClavier(const char touche);


};


#endif