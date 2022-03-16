#include <iostream>
#include <string>
#include "Personnage.h"
#include "Arme.h"

#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include "SDL2/SDL_image.h"
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>


using namespace std;




int setWindowColor(SDL_Renderer *renderer, SDL_Color color)
{
    if(SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a) < 0)
        return -1;
    if(SDL_RenderClear(renderer) < 0)
        return -1;
    return 0;  
}


int main(int argc, char *argv[])
{
    

    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    SDL_Surface* image = IMG_Load("./data/image.png");
    SDL_Texture* monImage = NULL;
    SDL_Rect rectangle;
    SDL_Color orange = {255, 127, 40, 255};


    int statut = EXIT_FAILURE;

    if(0 != SDL_Init(SDL_INIT_VIDEO))
    {
        cout<<"Erreur SDL_Init : "<< SDL_GetError()<<endl;
        goto Quit;
    }

    window = SDL_CreateWindow("SDL2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                              640, 400, SDL_WINDOW_SHOWN); //| SDL_WINDOW_FULLSCREEN); //pour le plein ecran

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

    if(!image)
    {
    cout<<"Erreur de chargement de l'image : "<<SDL_GetError()<<endl;
    return -1;
    }

    monImage = SDL_CreateTextureFromSurface(renderer,image);  //La texture monImage contient maintenant l'image importée
    SDL_FreeSurface(image); //Équivalent du destroyTexture pour les surface, permet de libérer la mémoire quand on n'a plus besoin d'une surface



    /* On agit sur la fenêtre ici */

    //void SDL_MinimizeWindow(SDL_Window* window);  // pour réduire la fenetre dans la barre des taches(prototype)
    //void SDL_RestoreWindow(SDL_Window* window);  //pour restaurer la fenetre(prototype)


    int largeurFenetre, hauteurFenetre;
    SDL_GetWindowSize(window, &largeurFenetre, &hauteurFenetre); //pour recuperer la largeur de la fenetre
    rectangle  = {0, 0, largeurFenetre, hauteurFenetre};
    SDL_RenderFillRect(renderer, &rectangle);  //dessine un rectangle plein (si on désactive la couleur on peut voir appairaitre le rectangle !)
    //SDL_RenderClear(renderer);

    SDL_RenderCopy(renderer, monImage, NULL,&rectangle);


    //setWindowColor(renderer, orange); //pour mettre a jour la couleur de la fenetre
    SDL_Delay(1000);
    SDL_RenderPresent(renderer);
    SDL_Delay(5000);
    statut = EXIT_SUCCESS;
Quit:
    if(NULL != renderer)
        SDL_DestroyRenderer(renderer);
    if(NULL != window)
        SDL_DestroyWindow(window);
    SDL_Quit();
    return statut;





    Personnage premier, deuxieme;

    premier.attaquer(deuxieme);
    //cout << "appuyer sur E pour lancer une attaque a l'arme " << endl;
    deuxieme.attaqueMagique(premier);
    premier.changerArme("arme qui encule des races", 90);
    premier.attaquer(deuxieme);
    deuxieme.attaqueMagique(premier);
    premier.estVivant();
    deuxieme.estVivant();
    


    

    cout << endl;
    premier.afficherEtat();
    cout << endl; 
    deuxieme.afficherEtat();

    return 0;


    


}