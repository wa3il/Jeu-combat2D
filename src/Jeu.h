#ifndef JEU_H
#define JEU_H

#include <iostream>
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
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

    public:
        Jeu();
       
        void init();
        void boucle();
        void quit();

};



#endif