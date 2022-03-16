#include <iostream>
#include <string>
#include "Personnage.h"
#include "Arme.h"


using namespace std;

int main()
{
    

    //Personnage david, goliath;
    ////Création de 2 objets de type Personnage : david et goliath

    //goliath.attaquer(david); //goliath attaque david
    //david.boirePotionDeVie(20); //david récupère 20 de vie en buvant une potion
    //goliath.attaquer(david); //goliath réattaque david
    //david.attaquer(goliath); //david contre-attaque... c'est assez clair non ? 
    //goliath.changerArme("Double hache tranchante veneneuse de la mort", 40);
    //goliath.attaquer(david);
    //david.boirePotionDeVie(10); //david récupère 10 de vie en buvant une potion
    //david.changerArme("Sabre enflame", 50);
    //david.attaquer(goliath);
    //goliath.attaquer(david);
    //david.attaqueMagique(goliath);

    Personnage premier, deuxieme;

    premier.attaquer(deuxieme);
    //cout << "appuyer sur E pour lancer une attaque a l'arme " << endl;
    deuxieme.attaqueMagique(premier);
    premier.changerArme("arme qui encule des races", 90);
    premier.attaquer(deuxieme);
    deuxieme.attaqueMagique(premier);
    premier.estVivant();
    deuxieme.estVivant();
    

   /*for (int i = 0; i < 10;i++)
   {
       cout << "joueur 1 : " << premier.getNom() << endl;
       

   }*/

    

    cout << endl;
    premier.afficherEtat();
    cout << endl; 
    deuxieme.afficherEtat();

    return 0;


    


}