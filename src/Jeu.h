#ifndef JEU_H
#define JEU_H

#include "Personnage.h"
#include "terrain.h"

class Jeu{
    private:



    public:
    terrain ter1;
    Personnage MP;
    Personnage SP;
    void actionsClavier(const char touche);
    void actionsAutomatique();

};


#endif