/**
 * @file Personnage.h
 * @brief fichier de déclaration de la class Personnage
 * @version 0.1
 * @date 2022-05-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef PERSONNAGE_H
#define PERSONNAGE_H

#include <cassert>
#include "Competence.h"
#include "Physic.h"
#include "Texture.h"
#include "Terrain.h"

/**
 * \class Personnage
 * \brief permettant de gerer les caracteristiques d'un personnage
 * 
 */
class Personnage
{
public:

    /**
     * @brief Construct a new Personnage object
     * 
     */
    Personnage();
    /**
     * @brief Destroy the Personnage object
     * 
     */
    ~Personnage();


    //mouvements
    /** 
     * @fn permettant de gerer les mouvements d'un personnage
     * @brief vers la droite
     * 
     */
    void bougerAdroite(terrain& t);
    /** 
     * @fn permettant de gerer les mouvements d'un personnage
     * @brief vers la gauche
     * 
     */
    void bougerAgauche(terrain& t);
    /** 
     * @fn permettant de gerer les mouvements d'un personnage
     * @brief vers le haut
     * 
     */
    void sauter(terrain& t);
    /** 
     * @fn permettant de gerer les mouvements d'un personnage
     * @brief vers en haut à droite
     * 
     */
    void sauterAdroite(float& t);
    /** 
     * @fn permettant de gerer les mouvements d'un personnage
     * @brief vers en haut a gauche
     * 
     */
    void sauterAgauche();

    //Attaques et Compétences
    /** 
     * @brief un personnage recoit des dégats
     * @param nbDegats 
     * 
     */
    void recevoirDegats(int nbDegats);
    /** 
     * @brief la cible recoit des dégats
     * @param cible
     * 
     */
    void attaquer(Personnage& cible);
    /** 
     * @brief un personnage recoit des dégats
     * @param cible
     */
    void attaqueUltime(Personnage& cible);
    /**
     * @brief permet de changer le nombre de degat
     * @param degatsNouvelleCompetence 
     */
    void changerCompetence(int degatsNouvelleCompetence);

    /**
     * @brief retourne vrai si le personnage a plus de 100 hp
     * @return true 
     * @return false 
     */
    bool estVivant() const;
    /**
     * @brief affichage de l'etat des points de vie
     */
    void afficherEtat() const;
    /**
     * @brief Get the Vie object
     * 
     * @return int 
     */
    int getVie();
    /**
     * @brief Set the Vie object
     * 
     * @param vie 
     */
    void setVie(int vie);

    //test Regression
    /**
     * @brief test de regression
     * 
     */
    void testRegression();

    Physic phy;/*!< les vecteurs d'un personnage */
    Texture tex;/*!< les textures d'un personnage */

private:
   
    int m_vie;/*!< Point de vie */
    int m_mana;/*!< mana */
    Competence *m_competence;/*!< competance d'un personnage */
    
};




#endif