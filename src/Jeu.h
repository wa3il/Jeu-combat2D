#ifndef JEU_H
#define JEU_H


#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>

#include "Personnage.h"



class Jeu{
    private:
        SDL_Window *window;
        SDL_Renderer *renderer;
        
        //Image im_background;

        Personnage MP;

    public:
        Jeu();

        SDL_Texture* loadImage(const char* filename);

        void init();
        void boucle();
        void quit();

};



#endif