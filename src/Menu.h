/**
 * @file Menu.h
 * @brief fichier de déclaration de la class Menu et bouton
 * @version 0.1
 * @date 2022-05-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

#include "Texture.h"

/**
 * \class Bouton
 * \brief permettant de gerer les boutons du menu
 * 
 */
class Bouton{
   
    public:

    /**
     * @brief Construct a new Bouton object
     * 
     */
    Bouton();
    
    Texture tex;

    /**
     * @brief methode permmetant de placer les coordonnées des boutons
     * 
     * @param x 
     * @param y 
     * @param w 
     * @param h 
     */
    void placerBouton(int x , int y, int w, int h);

    /**
     * @brief Accesseur de la position x
     * 
     * @return int 
     */
    int getx()const ;

    /**
     * @brief Accesseur de la position y
     * 
     * @return int 
     */
    int gety()const ;

    /**
     * @brief Accesseur de la position w
     * 
     * @return int 
     */
    int getw()const ;

    /**
     * @brief Accesseur de la position w
     * 
     * @return int 
     */
    int geth()const ;
    
    private:
    int b_x,b_y;/*!< position x,y */
    int b_w,b_h;/*!< position w,h */

    enum etatBouton{
        Pressed = 0,
        Released = 1
    };
};

/**
 * \class Menu
 * \brief permettant de gerer le menu
 * 
 */
class Menu{
   
    public:
    /**
     * @brief Construct a new Menu object
     * 
     */
    Menu();

    /**
     * @brief Construct a new Menu object
     * 
     * @param w 
     * @param h 
     */
    Menu(int w , int h);
    
    Texture tex;/*!< texture du bouton */
    
    Bouton start;/*!< bouton start */
    Bouton quit;/*!< bouton quit */
    Bouton back;/*!< bouton back */
    Bouton son;/*!< bouton son */
    private:
    int m_w , m_h ;/*!< taille du menu */
    
   
};






#endif