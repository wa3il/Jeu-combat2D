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
 
        Jeu J;



    public:
        JeuSDL();


        SDL_Texture* loadImage(const char* filename);
        void Afficher(SDL_Texture *texture, SDL_Surface* tileset,int nbl,int nbh);
        //void loadSprite();

        void KeyboardEventsLuffy(bool &isSprite);
        void KeyboardEventsZoro(bool &isSprite);
        void clavierUP(SDL_Event events);

        void init();
        void bouclePartie();
        void boucleAcceuil();
        void quit();



};



#endif