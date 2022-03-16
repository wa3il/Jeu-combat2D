#include "Jeu.h"


using namespace std;


Jeu::Jeu(){

};

void Jeu::init(){
     if(0 != SDL_Init(SDL_INIT_VIDEO))
    {
        cout<<"Erreur SDL_Init : "<< SDL_GetError()<<endl;
        
    }

     window = SDL_CreateWindow("SDL2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                              640, 400, SDL_WINDOW_SHOWN); //| SDL_WINDOW_FULLSCREEN); //pour le plein ecran

    if(NULL == window)
    {
        cout<< "Erreur SDL_CreateWindow : "<< SDL_GetError()<<endl;
        
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if(NULL == renderer)
    {
        cout<<"Erreur SDL_CreateRenderer : "<<SDL_GetError()<<endl;
        
    }
     
}

void Jeu::boucle(){

  

    SDL_Surface * image = IMG_Load("./data/image.png");

    if(!image)
    {
    cout<<"Erreur de chargement de l'image : "<< SDL_GetError()<<endl;
    }

    Personnage MainPlayer ;

    SDL_Texture * monImage = SDL_CreateTextureFromSurface(renderer,image);  //La texture monImage contient maintenant l'image importée
    SDL_FreeSurface(image); //Équivalent du destroyTexture pour les surface, permet de libérer la mémoire quand on n'a plus besoin d'une surface

 /* On agit sur la fenêtre ici */

    //void SDL_MinimizeWindow(SDL_Window* window);  // pour réduire la fenetre dans la barre des taches(prototype)
    //void SDL_RestoreWindow(SDL_Window* window);  //pour restaurer la fenetre(prototype)

    int largeurFenetre, hauteurFenetre;
    SDL_GetWindowSize(window, &largeurFenetre, &hauteurFenetre); //pour recuperer la largeur de la fenetre
    SDL_Rect rectangle  = {0, 0, largeurFenetre, hauteurFenetre};


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
                
                case SDL_KEYDOWN: // Un événement de type touche enfoncée est effectué
                if (events.key.keysym.scancode == SDL_SCANCODE_D){ // Regarde si le scancode W est enfoncé (Z sous un azerty)
                
                MainPlayer.bougerAdroite(15);
                cout<<MainPlayer.x<<endl; // Affiche un message
                }

                break;
                 
            }
            
        }
        
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Choisir la couleur noir  
        SDL_RenderClear(renderer); // Colorier en noir toutes la fenêtre 
    
         SDL_RenderFillRect(renderer, &rectangle); 
         SDL_RenderCopy(renderer, monImage, NULL,&rectangle);

        SDL_RenderPresent(renderer);

    }

}

void Jeu::quit(){

    if(NULL != renderer)
        SDL_DestroyRenderer(renderer);
    if(NULL != window)
        SDL_DestroyWindow(window);
    SDL_Quit();
    
}


