#ifndef JEU_H
#define JEU_H

#include "Personnage.h"
//#include "Terrain.h"

class Jeu{
    private:


    //Terrain Teradnane;

    public:
    Personnage MP;
    Personnage SP;
    void actionsClavier(const char touche);

};


#endif