#include <cassert>
#include <time.h>
#include <stdlib.h>

#include "Jeu.h"

#include <iostream>
using namespace std;


Jeu::Jeu(){
    
};

int Jeu::lancerJeu(){

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", SDL_GetError());
        return EXIT_FAILURE;
    }
    SDL_Window* pWindow{ nullptr };     
    SDL_Renderer* pRenderer{ nullptr };
    if (SDL_CreateWindowAndRenderer(800, 600, SDL_WINDOW_SHOWN, &pWindow, &pRenderer) < 0)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", SDL_GetError());        
        SDL_Quit(); 
        return EXIT_FAILURE;
    }
    SDL_Event events;
    bool isOpen{ true };
    while (isOpen)
    {
        while (SDL_PollEvent(&events))
        {
            switch (events.type)
            {
                case SDL_QUIT:
                    isOpen = false;
                    break;
            }
        }
    }
    SDL_DestroyRenderer(pRenderer);SDL_DestroyWindow(pWindow);
    SDL_Quit();
 
    return EXIT_SUCCESS;
}
