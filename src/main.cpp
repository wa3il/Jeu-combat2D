#include <iostream>
#include <string>
#include "Personnage.h"
#include "Arme.h"

using namespace std;


int main(void){

    Personnage premier, deuxieme;

    premier.attaquer(deuxieme);
    //cout << "appuyer sur E pour lancer une attaque a l'arme " << endl;
    deuxieme.attaqueMagique(premier);
    premier.changerArme("arme qui encule des races", 90);
    premier.attaquer(deuxieme);
    deuxieme.attaqueMagique(premier);
    premier.estVivant();
    deuxieme.estVivant();
    


    

    cout << endl;
    premier.afficherEtat();
    cout << endl; 
    deuxieme.afficherEtat();

    return 0;


    


}