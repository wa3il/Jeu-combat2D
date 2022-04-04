#include "Jeu.h"
#include "JeuSDL.h"
using namespace std;


int main(void){

    JeuSDL j1;
    j1.init();
    j1.boucleAcceuil();
    j1.quit();

    /*
    //pour essayer test régression : 
    Personnage p;
    p.testRegression();
    */


    /* Personnage premier, deuxieme;

    premier.attaquer(deuxieme);
    //cout << "appuyer sur E pour lancer une attaque a l'arme " << endl;
    deuxieme.attaqueMagique(premier);
    premier.changerCompetence("arme qui encule des races", 90);
    premier.attaquer(deuxieme);
    deuxieme.attaqueMagique(premier);
    premier.estVivant();
    deuxieme.estVivant();
    
    cout << endl;
    premier.afficherEtat();
    cout << endl; 
    deuxieme.afficherEtat();
 */
    return 0;


    


}