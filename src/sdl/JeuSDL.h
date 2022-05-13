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


class JeuSDL{
    private:
        SDL_Window *window;
        SDL_Renderer *renderer;
 
        Jeu action;
        //SDL_Rect spriteluffy[ 8 ];


    public:
        JeuSDL();


        SDL_Texture* loadImage(const char* filename);
        void Afficher(SDL_Renderer *renderer,SDL_Texture *texture, SDL_Surface* tileset,int nbl,int nbh);
        //void loadSprite();
        

        void init();
        void bouclePartie();
        void boucleAcceuil();
        void quit();

};



#endif