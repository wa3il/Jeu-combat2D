/**
 * @file Texture.h
 * @brief fichier de déclaration de la class texture
 * @version 0.1
 * @date 2022-05-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef TEXTURE_H
#define TEXTURE_H

#include<string>
using namespace std;


/**
 * \class Texture
 * \brief class permettant de gerer les textures d'un personnage
 */
class Texture{

    private:
    
    public:
    
    const char* url; /*!< url de la texture d'un personnage */
    const char* lettre;/*!< lettre d'un personnage */
    //bool isSprite;

    /**
     * @brief Construct a new Texture object
     * 
     */
    Texture();

  
};


#endif