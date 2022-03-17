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




    // Background 1
    SDL_Surface * image = IMG_Load("./data/image.png");

    if(!image)
    {
    cout<<"Erreur de chargement de l'image : "<< SDL_GetError()<<endl;
    }

    SDL_Texture * monImage = SDL_CreateTextureFromSurface(renderer,image);  //La texture monImage contient maintenant l'image importée
    SDL_FreeSurface(image); //Équivalent du destroyTexture pour les surface, permet de libérer la mémoire quand on n'a plus besoin d'une surface






    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    // MainPlayer Image
    SDL_Surface * imPlayerD = IMG_Load("./data/luffyDroit.png");

    if(!imPlayerD)
    {
    cout<<"Erreur de chargement de l'image : "<< SDL_GetError()<<endl;
    }

    SDL_Texture * texPlayerD = SDL_CreateTextureFromSurface(renderer,imPlayerD);  //La texture monImage contient maintenant l'image importée
    SDL_FreeSurface(imPlayerD); //Équivalent du destroyTexture pour les surface, permet de libérer la mémoire quand on n'a plus besoin d'une surface




    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    //luffy gauche

    SDL_Surface * imPlayerG = IMG_Load("./data/luffyGauche.png");

    if(!imPlayerG)
    {
    cout<<"Erreur de chargement de l'image : "<< SDL_GetError()<<endl;
    }

    SDL_Texture * texPlayerG = SDL_CreateTextureFromSurface(renderer,imPlayerG);  //La texture monImage contient maintenant l'image importée
    SDL_FreeSurface(imPlayerG); //Équivalent du destroyTexture pour les surface, permet de libérer la mémoire quand on n'a plus besoin d'une surface

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



    //void SDL_MinimizeWindow(SDL_Window* window);  // pour réduire la fenetre dans la barre des taches(prototype)
    //void SDL_RestoreWindow(SDL_Window* window);  //pour restaurer la fenetre(prototype)





    //Recuperation de taille de fenetre
    int DIMX, DIMY;
    SDL_GetWindowSize(window, &DIMX, &DIMY); //pour recuperer la largeur de la fenetre
    //
    SDL_Rect rectangle  = {0, 0, DIMX, DIMY};

   



    //infos joueurs
    MP.x = 40;
    MP.y = 40;


    //interupteur :

    bool profilGauche = true;

    


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
                switch(events.key.keysym.sym)
                {
                        case SDLK_ESCAPE:    // Regarde si le scancode W est enfoncé (Z sous un azerty)
                        isOpen = false;                
                        break;

                        case SDLK_d:
                        MP.bougerAdroite(10);
                        cout <<"x =" << MP.x <<endl; 
                        profilGauche=false;     
                        break;        

                        case SDLK_q:
                        MP.bougerAgauche(10);
                        cout << "x =" << MP.x <<endl;  
                        profilGauche=true;    
                        break;       

                        case SDLK_z:
                        MP.sauter(10);
                        cout <<"y =" << MP.y <<endl;
                        break;             

                }

            break;

            }
        }

        SDL_Rect rectPlayer  = SDL_Rect{MP.x,MP.y, 80, 100};

        
       
       //couleur noire par default
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); 
        SDL_RenderClear(renderer);  

        //Background
        SDL_RenderFillRect(renderer, &rectangle); 
        SDL_RenderCopy(renderer, monImage, NULL,&rectangle );
        

        //image luffy
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
        SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
        SDL_RenderFillRect(renderer, &rectPlayer); 


        if (profilGauche){
            SDL_RenderCopy(renderer, texPlayerG, NULL,&rectPlayer );
        }

        else {
            SDL_RenderCopy(renderer, texPlayerD, NULL,&rectPlayer );
        }


        /////////////////////////////////////////////////////////////////////////////////////////
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


