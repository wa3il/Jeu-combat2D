#ifndef JEUSDL_H
#define JEUSDL_H


#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>

#include "Personnage.h"
#include "Jeu.h"



class JeuSDL{
    private:
        SDL_Window *window;
        SDL_Renderer *renderer;
        
        //Image im_background;


        Jeu action;

    public:
        JeuSDL();





        SDL_Texture* loadImage(const char* filename);
        bool check_collision( SDL_Rect &A, SDL_Rect &B );
        

        void init();
        void boucle();
        void quit();

};



#endif