#ifndef PERSONNAGE_H
#define PERSONNAGE_H

#include "Arme.h"


class Personnage
{
public:


    Personnage(); //constructeur
    Personnage(std::string nom, std::string nomArme, int degatsArme);
    Personnage(std::string nom, int vie, int mana);

    Personnage(Personnage const& personnageACopier);
    //Le prototype du constructeur de copie

    ~Personnage(); //destructeur
    void bougerAdroite(int xd);
    void bougerAgauche(int xg);
    void sauter(int yh);

    void recevoirDegats(int nbDegats);
    void attaquer(Personnage& cible);
    void attaqueMagique(Personnage& cible);
    void boirePotionDeVie(int quantitePotion);
    void changerArme(std::string nomNouvelleArme, int degatsNouvelleArme);
    bool estVivant() const;

    void afficherEtat() const;
    std::string getNom() const;

    

private:

    std::string m_nom;
    int m_vie;
    int m_mana;
    Arme *m_arme;
    int x ;
    int y ;
};




#endif