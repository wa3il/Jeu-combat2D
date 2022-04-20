#ifndef JEUSDL_H
#define JEUSDL_H


#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>

#include "Personnage.h"
#include "Jeu.h"

#define LARGEUR_TILE 175
#define HAUTEUR_TILE 44

#define NOMBRE_BLOCS_LARGEUR 15
#define NOMBRE_BLOCS_HAUTEUR 18


class JeuSDL{
    private:
        SDL_Window *window;
        SDL_Renderer *renderer;
        //Les surfaces


        
        //Image im_background;
        Jeu action;

    public:
        JeuSDL();


        SDL_Texture* loadImage(const char* filename);
        void Afficher(SDL_Renderer *renderer,SDL_Texture *texture, SDL_Surface* tileset,int nbl,int nbh);
        

        void init();
        void bouclePartie();
        void boucleAcceuil();
        void quit();

};



#endif