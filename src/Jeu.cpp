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

SDL_Texture* Jeu::loadImage(const char* filename){

    SDL_Surface * image = IMG_Load(filename);

    if(!image)
    {
    cout<<"Erreur de chargement de l'image : "<< SDL_GetError()<<endl;
    }

    return SDL_CreateTextureFromSurface(renderer,image);  //La texture monImage contient maintenant l'image importée
    SDL_FreeSurface(image); //Équivalent du destroyTexture pour les surface, permet de libérer la mémoire quand on n'a plus besoin d'une surface
}


bool Jeu::check_collision( SDL_Rect &A, SDL_Rect &B )
{
    //Les cotes des rectangles
    int gaucheA, gaucheB;
    int droiteA, droiteB;
    int hautA, hautB;
    int basA, basB;
            
    //Calcul les cotes du rectangle A
    gaucheA = A.x;
    droiteA = A.x + A.w;
    hautA = A.y;
    basA = A.y + A.h;
            
    //Calcul les cotes du rectangle B
    gaucheB = B.x;
    droiteB = B.x + B.w;
    hautB = B.y;
    basB = B.y + B.h;


    //Tests de collision
    if( basA == basB )
    {
        return true;
    }
            
    if( hautA == hautB )
    {
        return true;
    }
            
    if( droiteA == droiteB )
    {
        return true;
    }
            
    if( gaucheA == gaucheB )
    {
        return true;
    }
            
    //Si conditions collision detectee
    return false;
        
}




void Jeu::boucle(){



    // Background 1

    SDL_Texture* monImage = loadImage("./data/image.png");


    // luffy droite

    SDL_Texture * texMPlayerD = loadImage("./data/luffyDroit.png");
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    //luffy gauche

    SDL_Texture * texMPlayerG = loadImage("./data/luffyGauche.png");

    //ichigo droite

    SDL_Texture * texSPlayerD = loadImage("./data/ichigoDroit.png");

    //ichigo gauche

    SDL_Texture * texSPlayerG = loadImage("./data/ichigoGauche.png");

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



    //void SDL_MinimizeWindow(SDL_Window* window);  // pour réduire la fenetre dans la barre des taches(prototype)
    //void SDL_RestoreWindow(SDL_Window* window);  //pour restaurer la fenetre(prototype)





    //Recuperation de taille de fenetre
    int DIMX, DIMY;
    SDL_GetWindowSize(window, &DIMX, &DIMY); //pour recuperer la largeur de la fenetre
    //
    SDL_Rect rectangle  = {0, 0, DIMX, DIMY};

   



    //infos joueurs
    //1
    MP.x = 40;
    MP.y = 40;
    //2
    SP.x = 600;
    SP.x = 40;


    //interupteur :

    bool profilGaucheMP = true;
    bool profilGaucheSP = true;




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
                            cout <<"MP.x =" << MP.x <<endl; 
                            profilGaucheMP=false;
                        break;    
                            

                        case SDLK_q:
                            MP.bougerAgauche(10);
                            cout << "MP.x =" << MP.x <<endl;  
                            profilGaucheMP=true;    
                        break;       

                        case SDLK_z:
                            MP.sauter(10);
                            cout <<"MP.y =" << MP.y <<endl;
                        break;

                        case SDLK_LEFT:
                            SP.bougerAgauche(10);     
                            cout << "SP.x =" << SP.x <<endl; 
                            profilGaucheSP=true;
 
                        break;

                        case SDLK_RIGHT:
                            SP.bougerAdroite(10);     
                            cout << "SP.x =" << SP.x <<endl;  
                            profilGaucheSP=false;

                        break;

                }

            break;

            }

        }



SDL_Rect rectMPlayer  = {MP.x,MP.y+245, 80, 100};
SDL_Rect rectSPlayer  = {500,SP.y+265, 100, 120};


if (check_collision(rectMPlayer, rectangle))
    { 
        /*
        // collision droite
        if(rectMPlayer.x >640) {
            MP.x =620;
        }
        // collision gauche
        if(rectMPlayer.x < 0) {
            MP.x = 0;
        } */
     
        MP.x=0;
        
    }




        
       
       //couleur noire par default
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); 
        SDL_RenderClear(renderer);  

        //Background
        SDL_RenderFillRect(renderer, &rectangle); 
        SDL_RenderCopy(renderer, monImage, NULL,&rectangle );
        

        //image luffy
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
        SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
        SDL_RenderFillRect(renderer, &rectMPlayer); 

        //image ichigo
        SDL_RenderFillRect(renderer, &rectSPlayer); 

            



        if (profilGaucheMP){ SDL_RenderCopy(renderer, texMPlayerG, NULL,&rectMPlayer );}
        else {SDL_RenderCopy(renderer, texMPlayerD, NULL,&rectMPlayer );}

        if (profilGaucheSP){ SDL_RenderCopy(renderer, texSPlayerG, NULL,&rectSPlayer );}
        else {SDL_RenderCopy(renderer, texSPlayerD, NULL,&rectSPlayer );}



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


