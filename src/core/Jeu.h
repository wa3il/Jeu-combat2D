#ifndef JEU_H
#define JEU_H

#include"../Menu.h"
#include "../Personnage.h"
#include "../Terrain.h"
#include "../Constantes.h"




class Jeu{
    private:



    public:
    

    Personnage MP;
    Personnage SP;
    terrain ter1;
    Menu menu;

  
    void actionsAutomatique(float deltaTime);//évenements automatiques
    void actionsClavier(const char touche, const float deltaTime); //gestion des évenements liés au clavié
    void actionsMenu(int clic); //gestion des événements liés à la souris

    //fct concernant le deroulement de la partie
    void initPartie();
    void updatePartie();
    void quitPartie();


    void init();//initialisation du jeu
    void update(); //update
    void quit(); //terminaison

};


#endif