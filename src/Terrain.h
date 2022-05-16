/**
 * @file Terrain.h
 * @brief fichier de déclaration de la class terrain
 * @version 0.1
 * @date 2022-05-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef TERRAIN_H
#define TERRAIN_H

#include <iostream>
#include "Texture.h"
#include "Constantes.h"
#include "Vector2D.h"

/**
 * \class Terrain
 * \brief class permettant de gerer un terrain
 */
class terrain{
    private:
        int dimx,dimy; /*!< dimension du terrain */
        const char *caract[WINDOW_SIZE_WIDTH][WINDOW_SIZE_HEIGHT]; /*!< tableau de caractere */

    public:
        /** 
         * @brief Construct a new terrain object
         * 
         */
        terrain();

        /**
         * @brief Destroy the terrain object
         * 
         */
        ~terrain(); 

        /** Fonction posisvalide
         * @brief position est valide (parametre : x et y ) => vrai ou faux
         *  
         */
        bool posisvalide(int x, int y);

        /** Fonction getXY
         * @brief caractère à une case (parametre : x et y ) => charactère
         * 
         */
        const char* getXY(int x,int y);

        /**
         * @brief getDimension () => entier
         * 
         */
        int getDimx();
        int getDimy();

        /**
         * @brief Set the Dim object
         * 
         * @param dimx 
         * @param dimy 
         */
        void setDim(int dimx, int dimy);
        void setCaract(int x,int y ,const char* car);

        Texture tex;

};

class Tuiles{

    private:

    public:
    Tuiles();
    Texture tex;
    Vector2D pos;
    int width , height;
    
};


#endif