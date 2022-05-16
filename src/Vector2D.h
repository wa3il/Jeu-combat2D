/**
 * @file Vector2D.h
 * @brief fichier de déclaration des classes rect et vector2D
 * @version 0.1
 * @date 2022-05-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef VECTOR2D_H
#define VECTOR2D_H
#include <iostream>

/**
 * \class Vector2D
 * \brief class permettant de gerer des vecteurs
 * 
 *  un vecteur est composé d'une cordonnée X et Y
 */
class Vector2D{
    private:
        float x,y; /*!< coordonnées X,Y */

    public:
        /**
         * @brief Constructeur par default 
         * 
         * constructeur de la classe Vector2D
         * 
         */
        Vector2D();

        /**
         * @brief Constructeur avec parametre x et y
         * 
         * constructeur de la classe Vector2D
         * 
         */
        Vector2D(float xpos,float ypos);

        /**
         * @brief Destructeur
         * 
         * Destructeur de la classe Vector2D
         * 
         */
        ~Vector2D();

        /**
         * @brief vecteur + vecteur2
         * 
         * Methode qui permet de retourner le resultat d'une addition
         * 
         * @param op 
         * @return Vector2D 
         */
        Vector2D operator+(const Vector2D& op)const;

        /**
         * @brief vecteur = vecteur2
         * 
         * Methode qui permet de prendre comme valeur celle d'un autre vecteur
         * 
         * @param op 
         * @return Vector2D 
         */
        Vector2D& operator =(const Vector2D& op);

        /**
         * @brief vecteur += vecteur2
         * 
         * Methode qui permet de prendre comme valeur celle d'un autre vecteur en addition
         * 
         * @param op 
         * @return Vector2D 
         */
        Vector2D& operator+=(const Vector2D& op);

        /**
         * @brief accesseur
         * 
         * accesseur de la coordonnée x du vecteur 
         * 
         * @return reel x 
         */
        float getx()const;

        /**
         * @brief accesseur
         * 
         * accesseur de la coordonnée y du vecteur 
         * 
         * @return reel xy
         */
        float gety()const;

        /**
         * @brief mutateur
         * 
         * mutateur de la coordonnée x du vecteur 
         * 
         * @param xpos
         */
        void setx(float xpos);

        /**
         * @brief mutateur
         * 
         * mutateur de la coordonnée y du vecteur 
         * 
         * @param ypos
         */
        void sety(float ypos);

};

        /**
         * @brief vecteur * valeur
         * 
         * Methode qui permet de mutliplier un vecteur par un reel
         * 
         * @param vec
         * @param f 
         * @return Vector2D 
         */
Vector2D operator*(const Vector2D& vec, float f);


/**
 * \class Rect
 * \brief class permettant de créer un rectangle
 * 
 *  Un rectangle est composé d'une coordonnée x,y,w,h
 */
class Rect{
    private:

    float x,y,w,h; /*!< coordonnées x,y,w,h pour la position ainsi que la taille du rectangle */


    public:

    /**
    * @brief Constructeur par default 
    * 
    * constructeur de la classe Rect
    * 
    */
    Rect();

    /**
    * @brief Constructeur avec parametre x,y,w,h
    * 
    * constructeur de la classe Rect
    * 
    */
    Rect(float x, float y , float w , float h);

    /**
    * @brief accesseur d'une coordonnée du rectangle
    * 
    * @return constante reel x 
    */
    float getx() const;
    float gety() const;
    float getw() const;
    float geth() const;

    /**
    * @brief mutateur
    * 
    * mutateur de la coordonnée y du vecteur 
    * 
    * paramettre reel;
    */
    void setx(float x);
    void sety(float y);
    void setw(float w);
    void seth(float h);
};

#endif