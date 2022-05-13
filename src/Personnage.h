#ifndef PERSONNAGE_H
#define PERSONNAGE_H

#include <cassert>
#include "Competence.h"
#include "Physic.h"
#include "Texture.h"

class Personnage
{
public:

    //constructeurs et destructeur
    Personnage(); //constructeur
    ~Personnage(); //destructeur


    //mouvements
    void bougerAdroite(float xd, const float deltaTime);
    void bougerAgauche(float xg, const float deltaTime);
    void sauter(float yh, const float deltaTime);

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
    Texture tex;

private:

   
    int m_vie;
    int m_mana;
    Competence *m_competence;
    
};




#endif