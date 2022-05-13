#ifndef PERSONNAGE_H
#define PERSONNAGE_H

#include <cassert>
#include "Competence.h"
#include "Physic.h"

class Personnage
{
public:

    //constructeurs et destructeur
    Personnage(); //constructeur
    ~Personnage(); //destructeur


    //mouvements
    void bougerAdroite(int xd);
    void bougerAgauche(int xg);
    void sauter(int yh);

    //Attaques et Compétences
    void recevoirDegats(int nbDegats);
    void attaquer(Personnage& cible);
    void attaqueUltime(Personnage& cible);
    void changerCompetence(int degatsNouvelleCompetence);

    //Vie et etat  
    void boirePotionDeVie(int quantitePotion);
    bool estVivant() const;
    void afficherEtat() const;
    int getVie();
    void setVie(int vie);

    //test Regression
    void testRegression();

     Physic phy;
    

private:

    //int texture[3];
    int m_vie;
    int m_mana;
    Competence *m_competence;
    
};




#endif