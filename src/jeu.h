#ifndef JEU_H
#define JEU_H

#include <iostream>
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main(int argc, char *argv[])
{


    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    //SDL_Rect rectangle;
    SDL_Color orange = {255, 127, 40, 255};

    int statut = EXIT_FAILURE;

    if(0 != SDL_Init(SDL_INIT_VIDEO))
    {
        cout<<"Erreur SDL_Init : "<< SDL_GetError()<<endl;
        goto Quit;
    }

    window = SDL_CreateWindow("SDL2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                              640, 480, SDL_WINDOW_SHOWN); //| SDL_WINDOW_FULLSCREEN); //pour le plein ecran

    if(NULL == window)
    {
        cout<< "Erreur SDL_CreateWindow : "<< SDL_GetError()<<endl;
        goto Quit;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if(NULL == renderer)
    {
        cout<<"Erreur SDL_CreateRenderer : "<<SDL_GetError()<<endl;
        goto Quit;
    }

    if(0 != SDL_SetRenderDrawColor(renderer, orange.r, orange.g, orange.b, orange.a))
    {
        cout<<"Erreur SDL_SetRenderDrawColor : "<<SDL_GetError()<<endl;
        goto Quit;
    }
   

    if(0 != SDL_RenderClear(renderer))
    {
        cout<<"Erreur SDL_SetRenderDrawColor : "<< SDL_GetError()<<endl;
        goto Quit;
    }
    /* On agit sur la fenêtre ici */

    //void SDL_MinimizeWindow(SDL_Window* window);  // pour réduire la fenetre dans la barre des taches(prototype)
    //void SDL_RestoreWindow(SDL_Window* window);  //pour restaurer la fenetre(prototype)


    /*int largeurFenetre, hauteurFenetre;
    SDL_GetWindowSize(window, &largeurFenetre, &hauteurFenetre); //pour recuperer la largeur de la fenetre
    rectangle.x=0;
    rectangle.y=0;
    rectangle.w= largeurFenetre;
    rectangle.h= hauteurFenetre;*/










    SDL_Delay(500);
    SDL_RenderPresent(renderer);
    SDL_Delay(500);

    statut = EXIT_SUCCESS;
Quit:
    if(NULL != renderer)
        SDL_DestroyRenderer(renderer);
    if(NULL != window)
        SDL_DestroyWindow(window);
    SDL_Quit();
    return statut;
}


#endif