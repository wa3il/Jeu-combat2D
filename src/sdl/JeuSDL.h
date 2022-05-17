/**
 * @file JeuSDL.h
 * @brief fichier d'implementation de la classeJeuSDl
 * @version 0.1
 * @date 2022-05-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef JEUSDL_H
#define JEUSDL_H


#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>

#include "../Personnage.h"
#include "../core/Jeu.h"
#include "../Constantes.h"

/**
 * \class JeuSdl
 * \brief permettant de gerer le jeu en version Sdl
 * 
 */
class JeuSDL{
    private:
        SDL_Window *window; /*!< fenetre SDL*/
        SDL_Renderer *renderer; /*!< renderer*/
 
        Jeu J;/*!< objet jeu*/

    public:
        /**
        * @brief Construct a new Jeu S D L object
        * 
        */
        JeuSDL();

        /**
         * @brief fonction chargeant une texture a partir d'une url
         * 
         * @param filename 
         * @return SDL_Texture* 
         */
        SDL_Texture* loadImage(const char* filename);

        /**
         * @brief affichage de l'objet
         * 
         * @param texture 
         * @param tileset 
         * @param nbl 
         * @param nbh 
         */
        void Afficher(SDL_Texture *texture, SDL_Surface* tileset,int nbl,int nbh);
        //void loadSprite();

        /**
         * @brief fonction gerant les deplacements de luffy
         * 
         * @param isSprite 
         */
        void KeyboardEventsLuffy(bool &isSprite, bool &attaque);

        /**
         * @brief fonction gerant les deplacements de zoro
         * 
         * @param isSprite 
         */
        void KeyboardEventsZoro(bool &isSprite, bool &attaque);

        /**
         * @brief fonction gerant le relachement d'une touche MP
         * 
         * @param events 
         */
        void MPclavierUP(SDL_Event events, bool & isSprite, bool &attaque);

        /**
         * @brief fonction gerant le relachement d'une touche SP
         * 
         * @param events 
         */
        
        void SPclavierUP(SDL_Event events, bool & isSprite, bool &attaque);

        /**
         * @brief initialisation d'SDL
         * 
         */
        void init();

        /**
         * @brief fonction gerant la boucle de la partie
         * 
         */
        void mainBoucle();

        /**
         * @brief quit
         * 
         */
        void quit();



};



#endif