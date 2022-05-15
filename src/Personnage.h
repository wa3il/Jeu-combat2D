#ifndef PERSONNAGE_H
#define PERSONNAGE_H

#include <cassert>
#include "Competence.h"
#include "Physic.h"
#include "Texture.h"
#include "Terrain.h"


class Personnage
{
public:

    //constructeurs et destructeur
    Personnage(); //constructeur
    ~Personnage(); //destructeur


    //mouvements
    void bougerAdroite(float xd,terrain& t);
    void bougerAgauche(float xg,terrain& t);
    void sauter(float yh,terrain& t);
    void sauterAdroite(float& t);
    void sauterAgauche();

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