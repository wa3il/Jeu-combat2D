#ifndef JEU_H
#define JEU_H

#include <iostream>
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include "SDL2/SDL_image.h"
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>

#include "Personnage.h"

class Image{
    private:
        /*
        SDL_Surface* surface;
        SDL_Texture* texture;
        bool has_changed;*/

    public:
        /*
        Image();
         PACMAN 
        void loadFromFile
        void loadFromCurrentSurface(SDL_Renderer * renderer);
        void draw(SDL_Renderer * renderer, int x,int y, int w=-1,int h=-1);
        SDL_Texture * getTexture() const;
        void setSurface(SDL_Surface * surf);*/ 
    };

class sdlJeu{
    private:
        SDL_Window *window;
        SDL_Renderer *renderer;
        SDL_Surface* image;
        SDL_Texture* texture;
        //Image im_background;

    public:
        sdlJeu();
        ~sdlJeu();
        void init();
        void boucle();
        void sdlAff();

};



#endif