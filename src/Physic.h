/**
 * @file Physic.h
 * @brief fichier de déclaration de la class Physic
 * @version 0.1
 * @date 2022-05-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef PHYSIC_H
#define PHYSIC_H

#include "Vector2D.h"
#include <time.h>

/**
 * \class Physic
 * \brief permettant de gerer les caracteristiques physique d'un joueur
 * 
 *  3 caracteristique à gerer : position,vitesse,acceleration
 */
class Physic
{
private:
    Vector2D m_position; /*!< Vecteur position */
    Vector2D m_vitesse; /*!< Vecteur vitesse */
    Vector2D m_acceleration; /*!< Vecteur acceleration */

public:
    /**
     * @brief Construct a new Physic object
     * 
     */
    Physic();

    /**
     * @brief Destroy the Physic object
     * 
     */
    ~Physic();

   // float t ;//time

    /**
     * @brief Get the Pos object
     * 
     * @return Vector2D 
     */
    Vector2D getPos() const;

    /**
     * @brief Get the Posx object
     * 
     * @return float 
     */
    float getPosx() const;

    /**
     * @brief Get the Posy object
     * 
     * @return float 
     */
    float getPosy() const;

    /**
     * @brief Set the Pos object
     * 
     * @param x 
     * @param y 
     */
    void setPos(float x, float y);

    /**
     * @brief Set the Posx object
     * 
     * @param x 
     */
    void setPosx(float x);

    /**
     * @brief Set the Posy object
     * 
     * @param y 
     */
    void setPosy(float y);

    /**
     * @brief Get the Vit object
     * 
     * @return Vector2D 
     */
    Vector2D getVit() const;

    /**
     * @brief Set the Vit object
     * 
     * @param x 
     * @param y 
     */
    void setVit(float x, float y);

    /**
     * @brief Set the Vitx object
     * 
     * @param x 
     */
    void setVitx(float x);

    /**
     * @brief Set the Vity object
     * 
     * @param y 
     */
    void setVity(float y);


    /**
     * @brief Set the Accy object
     * 
     * @param y 
     */
    void setAccy(float y);


    /**
     * @brief Fonction permettant d'activé la gravité
     * 
     * @param deltaTime 
     */
    void ticks(const float deltaTime);//gravité

    //bool PofloatRect(const Vector2D &p, const Rect &r);

};


#endif