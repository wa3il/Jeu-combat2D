#ifndef PERSONNAGE_H
#define PERSONNAGE_H

#include "Competence.h"


class Personnage
{
public:


    Personnage(); //constructeur
    Personnage(int x , int y);//
    Personnage(std::string nom, std::string nomCompetence, int degatsCompetence);
    Personnage(std::string nom, int vie, int mana);

    Personnage(Personnage const& personnageACopier);
    //Le prototype du constructeur de copie

    ~Personnage(); //destructeur
    void bougerAdroite(float xd);
    void bougerAgauche(float xg);
    void sauter(int yh);

    void recevoirDegats(int nbDegats);
    void attaquer(Personnage& cible);
    void attaqueMagique(Personnage& cible);
    void boirePotionDeVie(int quantitePotion);
    void changerCompetence(std::string nomNouvelleCompetence, int degatsNouvelleCompetence);
    bool estVivant() const;

    void afficherEtat() const;
    std::string getNom() const;

    int x ;
    int y ;

private:

    std::string m_nom;
    int m_vie;
    int m_mana;
    Competence *m_competence;
    
};




#endif