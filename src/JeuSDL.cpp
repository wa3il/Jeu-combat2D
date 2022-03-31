#include "JeuSDL.h"



using namespace std;



JeuSDL::JeuSDL(){

};

void JeuSDL::init(){
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

SDL_Texture* JeuSDL::loadImage(const char* filename){

    SDL_Surface * image = IMG_Load(filename);

    if(!image)
    {
    cout<<"Erreur de chargement de l'image : "<< SDL_GetError()<<endl;
    }

    return SDL_CreateTextureFromSurface(renderer,image);  //La texture monImage contient maintenant l'image importée
    SDL_FreeSurface(image); //Équivalent du destroyTexture pour les surface, permet de libérer la mémoire quand on n'a plus besoin d'une surface
}








bool JeuSDL::check_collision( SDL_Rect &A, SDL_Rect &B )
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




void JeuSDL::bouclePartie(){



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

    //Sprite luffy
    SDL_Texture * texSpriteLuffy = loadImage("./data/luffyCourt.png");

    //Sprite luffy accroupi
    SDL_Texture * texLuffyAccroupi = loadImage("./data/luffyAccroupi.png");


    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



    //void SDL_MinimizeWindow(SDL_Window* window);  // pour réduire la fenetre dans la barre des taches(prototype)
    //void SDL_RestoreWindow(SDL_Window* window);  //pour restaurer la fenetre(prototype)





    //Recuperation de taille de fenetre
    int DIMX, DIMY;
    SDL_GetWindowSize(window, &DIMX, &DIMY); //pour recuperer la largeur de la fenetre
    SDL_Rect rectangle  = {0, 0, DIMX, DIMY};

   



    //infos joueurs
    //1
    action.MP.setx(40);
    action.MP.sety(40);
    //2
    action.SP.setx(500);
    action.SP.sety(40);




    //interupteur :

    bool profilGaucheMP = true;
    bool profilGaucheSP = true;

    bool courir= false;




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
                        case SDLK_ESCAPE:  
                            isOpen = false;                
                        break;

                        case SDLK_d:
                            action.actionsClavier('d');
                            profilGaucheMP=false;
                            courir= true;
                        break;    
                            
                        case SDLK_q:
                            action.actionsClavier('g');
                            profilGaucheMP=true; 
                            courir= true;
   
                        break;       

                        case SDLK_z:
                            action.actionsClavier('z');
                            courir=false;
                        break;

                        case SDLK_LEFT:
                            action.actionsClavier('j');
                            profilGaucheSP=true;
 
                        break;

                        case SDLK_RIGHT:
                            action.actionsClavier('l');
                            profilGaucheSP=false;
                        break;

                        case SDLK_UP:
                            action.actionsClavier('i');
                        break;

                }
            break;

            }

        }


            Uint32 ticks = SDL_GetTicks();
            Uint32 sprite = (ticks / 100) % 8;
          



            SDL_Rect rectMPlayer  = {action.MP.getx(),action.MP.gety()+245, 80, 100};
            SDL_Rect rectSPlayer  = {action.SP.getx(),action.SP.gety()+230, 100, 120};

            SDL_Rect srcrect = { sprite * 42, 0, 40, 88 };
            SDL_Rect dstrect = { action.MP.getx(), action.MP.gety()+245, 80, 100 };



            //collision :
            /* MP */
            if (action.MP.getx() < -20) action.MP.setx(-20);  //collision gauche
            if (action.MP.getx() > DIMX-50) action.MP.getx() = DIMX-50; //collision droite
            
            /* SP */
            if (action.SP.getx() < -20) action.SP.setx(-20);  //collision gauche
            if (action.SP.getx() > DIMX-50) action.SP.getx() = DIMX-50; //collision droite
            
            //if (MP.gety() < 0)MP.gety() = 0;
            //if (MP.gety() > DIMY) MP.sety();

        
       
       //couleur noire par default
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); 
        SDL_RenderClear(renderer);  

        //Background
        SDL_RenderFillRect(renderer, &rectangle); 
        SDL_RenderCopy(renderer, monImage, NULL,&rectangle );
        

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
        SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

 



 // a revoir plutard :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::


        if (courir && !profilGaucheMP) {
            SDL_RenderCopy(renderer, texSpriteLuffy, &srcrect, &dstrect);
        }
        else if(courir && profilGaucheMP) {
            SDL_RenderCopyEx(renderer, texSpriteLuffy, &srcrect, &dstrect, 0, NULL, SDL_FLIP_HORIZONTAL);
        } 
        else if (!courir && profilGaucheMP){ SDL_RenderCopy(renderer, texMPlayerG, NULL,&rectMPlayer );}
        else  {SDL_RenderCopy(renderer, texMPlayerD, NULL,&rectMPlayer );}        
        
  // :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::         


       /* //image luffy
         SDL_RenderFillRect(renderer, &rectMPlayer); 
        if (profilGaucheMP){ SDL_RenderCopy(renderer, texMPlayerG, NULL,&rectMPlayer );}
        else {SDL_RenderCopy(renderer, texMPlayerD, NULL,&rectMPlayer );}  
 */




        //image ichigo
        SDL_RenderFillRect(renderer, &rectSPlayer);
        if (profilGaucheSP){ SDL_RenderCopy(renderer, texSPlayerG, NULL,&rectSPlayer );}
        else {SDL_RenderCopy(renderer, texSPlayerD, NULL,&rectSPlayer );}



        /////////////////////////////////////////////////////////////////////////////////////////
        SDL_RenderPresent(renderer);

    }
}









void JeuSDL::boucleAcceuil(){



    // Background Menu

    SDL_Texture* menuBg = loadImage("./data/menuBg.jpg");


    // Bouton play

    SDL_Texture * texMPlayerD = loadImage("./data/luffyDroit.png");
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    //Bouton params

    SDL_Texture * texMPlayerG = loadImage("./data/luffyGauche.png");

    //Bouton Help

    SDL_Texture * texSPlayerD = loadImage("./data/ichigoDroit.png");

    //Bouton quit 

    SDL_Texture * texSPlayerG = loadImage("./data/ichigoGauche.png");

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



    //void SDL_MinimizeWindow(SDL_Window* window);  // pour réduire la fenetre dans la barre des taches(prototype)
    //void SDL_RestoreWindow(SDL_Window* window);  //pour restaurer la fenetre(prototype)





    //Recuperation de taille de fenetre
    int DIMX, DIMY;
    SDL_GetWindowSize(window, &DIMX, &DIMY); //pour recuperer la largeur de la fenetre
    SDL_Rect rectangle  = {0, 0, DIMX, DIMY};



    //interupteur :


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
                    case SDLK_p:    // Regarde si le scancode W est enfoncé (Z sous un azerty)
                    this -> boucle();                     
                    break;
                };

                break;

            }

        }



        
       
       //couleur noire par default
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); 
        SDL_RenderClear(renderer);  

        //Background
        SDL_RenderFillRect(renderer, &rectangle); 
        SDL_RenderCopy(renderer, menuBg, NULL,&rectangle );
        


        /////////////////////////////////////////////////////////////////////////////////////////
        SDL_RenderPresent(renderer);

        //SDL_Delay();
    }
}



void JeuSDL::quit(){

    if(NULL != renderer)
        SDL_DestroyRenderer(renderer);
    if(NULL != window)
        SDL_DestroyWindow(window);

   
    SDL_Quit();
    
}


