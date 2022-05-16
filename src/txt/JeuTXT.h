/**
 * @file JeuTXT.h
 * @brief fichier de déclaration de la class JeuTxt
 * @version 0.1
 * @date 2022-05-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef _JEUTXT_H
#define _JEUTXT_H

#include <ncurses.h>
#include "JeuTXT.h"
#include "../core/Jeu.h"

/**
 * \class JeuTxt
 * \brief permettant de gerer le jeu en version txt
 * 
 */
class JeuTxt{
    public:
        
        Jeu Jtxt; /*!< objet jeu*/

        /**
         * @brief fonction gerant l'affichage du jeu en boucle
         * 
         */
        void txtBoucle();
        
        /**
         * @brief affichage du menu
         * 
         */
        void menuaff();

        /**
         * @brief affichage du terrain
         * 
         */
        void txtAff();

    private:

};


#endif