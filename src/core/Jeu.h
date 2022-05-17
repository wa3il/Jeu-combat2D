#ifndef JEU_H
#define JEU_H

#include"../Menu.h"
#include "../Personnage.h"
#include "../Constantes.h"




class Jeu{
    private:



    public:
    

    Personnage MP;
    Personnage SP;
    terrain ter1;
    Tuiles tuile[20];
    Menu menu;

  
    void actionsAutomatique();//évenements automatiques

    void MPClavierDown(int touche); //gestion des évenements liés au clavié
    void MPClavierUp(int touche);

    void SPClavierDown(int touche); 
    void SPClavierUp(int touche);

    void actionsMenu(int clic); //gestion des événements liés à la souris

    //fct concernant le deroulement de la partie
    void initPartie();
    void updatePartie(float deltaTime);
    void quitPartie();

    void init();//initialisation du jeu
    void update(); //update
    void quit(); //terminaison

};


#endif