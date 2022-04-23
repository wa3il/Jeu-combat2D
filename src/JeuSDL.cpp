#include "JeuSDL.h"

using namespace std;









JeuSDL::JeuSDL(){};




void JeuSDL::init(){
     if (0 != SDL_Init(SDL_INIT_VIDEO))  {cout<<"Erreur SDL_Init : "<< SDL_GetError()<<endl; }

     window = SDL_CreateWindow("SDL2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_SIZE_WIDTH, WINDOW_SIZE_HIGH, SDL_WINDOW_SHOWN);

    if(NULL == window)   {  cout<< "Erreur SDL_CreateWindow : "<< SDL_GetError()<<endl; }

        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if(NULL == renderer)   { cout<<"Erreur SDL_CreateRenderer : "<<SDL_GetError()<<endl; }
     
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





void JeuSDL::Afficher(SDL_Renderer *renderer,SDL_Texture *texture, SDL_Surface* tileset,int nbl,int nbh)
{
    int i,j;
    SDL_Rect Rect_dest;
    SDL_Rect Rect_source;
    Rect_dest.w = LARGEUR_TILE/2;
    Rect_dest.h = HAUTEUR_TILE;

    texture=SDL_CreateTextureFromSurface(renderer,tileset);
    for(i=0;i<NOMBRE_BLOCS_HAUTEUR;i++)
    {
        for(j=0;j<NOMBRE_BLOCS_LARGEUR;j++)
        {   
            if(action.ter1.getXY(i,j) == '#') {
                Rect_source.x=0;
                Rect_source.y=0;
                Rect_source.w=LARGEUR_TILE;
                Rect_source.h=HAUTEUR_TILE;

            }
            else {
                Rect_source = {NULL};
            
            }
            
                Rect_dest.x = j*LARGEUR_TILE/2;
                Rect_dest.y = i*HAUTEUR_TILE/2;
            

            SDL_RenderCopy(renderer, texture, &Rect_source, &Rect_dest);
            
            
        }

    }
    SDL_DestroyTexture(texture);
}





/* void JeuSDL::loadSprite(){


    //Load sprite sheet texture
    loadImage("./data/luffy/luffyCourt.png")
   
        //Set top left sprite
        spriteluffy[ 0 ].x =   0;
        spriteluffy[ 0 ].y =   0;
        spriteluffy[ 0 ].w = 50;
        spriteluffy[ 0 ].h = HAUTEUR_SPRITE1_LUFFY;

        //Set top right sprite
        spriteluffy[ 1 ].x =   50;
        spriteluffy[ 1 ].y =   0;
        spriteluffy[ 1 ].w = 50;
        spriteluffy[ 1 ].h = HAUTEUR_SPRITE1_LUFFY;
        
        //Set bottom left sprite
        spriteluffy[ 2 ].x = 100;
        spriteluffy[ 2 ].y =   0;
        spriteluffy[ 2 ].w = 55;
        spriteluffy[ 2 ].h = HAUTEUR_SPRITE1_LUFFY;

        //Set bottom right sprite
        spriteluffy[ 3 ].x =   155;
        spriteluffy[ 3 ].y =   0;
        spriteluffy[ 3 ].w = 55;
        spriteluffy[ 3 ].h = HAUTEUR_SPRITE1_LUFFY;
        
        //Set bottom right sprite
        spriteluffy[ 4 ].x =   210;
        spriteluffy[ 4 ].y =   0;
        spriteluffy[ 4 ].w = 40;
        spriteluffy[ 4 ].h = HAUTEUR_SPRITE1_LUFFY;        
        
        //Set bottom right sprite
        spriteluffy[ 5 ].x =   250;
        spriteluffy[ 5 ].y =   0;
        spriteluffy[ 5 ].w = 45;
        spriteluffy[ 5 ].h = HAUTEUR_SPRITE1_LUFFY;
        
        //Set bottom right sprite
        spriteluffy[ 6 ].x =   300;
        spriteluffy[ 6 ].y =   0;
        spriteluffy[ 6 ].w = 52;
        spriteluffy[ 6 ].h = HAUTEUR_SPRITE1_LUFFY;        
        
        //Set bottom right sprite
        spriteluffy[ 7 ].x =   350;
        spriteluffy[ 7 ].y =   0;
        spriteluffy[ 7 ].w = 55;
        spriteluffy[ 7 ].h = HAUTEUR_SPRITE1_LUFFY;
        

    }

} */









void JeuSDL::bouclePartie(){

        clock_t start = clock();
        //std::cout<<start<<std::endl;



    // Background 1
    SDL_Texture* monImage = loadImage("./data/background/sunny.jpg");




    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    //luffy gauche
    SDL_Texture * texMPlayerG = loadImage("./data/luffy/luffy.png");

    //Sprite luffy court
    SDL_Texture * texLuffyCourt = loadImage("./data/luffy/luffyCourt.png");

    //Sprite luffy accroupi
    SDL_Texture * texLuffyAccroupi = loadImage("./data/luffy/luffyAccroupi.png");

    //Sprite luffy attaque
    SDL_Texture * texLuffyAttaque = loadImage("./data/luffy/luffyAttaque.png");

    
    //zoro gauche
    SDL_Texture * texSPlayerG = loadImage("./data/zoro/zoro.png");
    
    //zoro marche
    SDL_Texture * texZoroMarche = loadImage("./data/zoro/zoroMarche.png");


    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



    //Recvtangle fenetre : 
    SDL_Rect rectangle  = {0, 0, WINDOW_SIZE_WIDTH, WINDOW_SIZE_HIGH};







    SDL_Event events;

    //interupteur :
    bool isOpen = true;
    bool profilGaucheMP = true;
    bool profilGaucheSP = true;
    bool courir = false;
    bool accroupi = false;
    bool attaqueA = false;
    bool marche = false;



    while (isOpen)
    {

        clock_t end = clock();
        //std::cout<<"end  : "<<end<<std::endl;

        float deltaTime = (end - start) / CLOCKS_PER_SEC;
        //std::cout<<"delta Time "<<deltaTime<<std::endl;
       // start = end;


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
                                profilGaucheMP=false;
                                courir= true;
                            break;    
                                
                            case SDLK_q:
                                profilGaucheMP=true; 
                                courir= true;
                            break;       

                            case SDLK_z:
                                action.actionsClavier('z');
                            break;
            
                            case SDLK_s:
                                accroupi=true;
                            break;

                            case SDLK_a:
                                action.actionsClavier('t');
                                attaqueA = true;
                            break;

                            case SDLK_LEFT:
                                profilGaucheSP=true;
                                marche= true;
                            break;

                            case SDLK_RIGHT:
                                profilGaucheSP=false;
                                marche= true;
                            break;

                            case SDLK_UP:
                                action.actionsClavier('i');
                            break;

                    }
                break;
                
                case SDL_KEYUP:
                    switch(events.key.keysym.sym)
                    {

                            case SDLK_d:
                                profilGaucheMP=false;
                                courir= false;
                            break;    
                                
                            case SDLK_q:
                                action.actionsClavier('g');
                                profilGaucheMP=true; 
                                courir= false;
    
                            break;       

                            case SDLK_z:
                                action.actionsClavier('z');
                                courir=false;
                            break;

                            case SDLK_s:
                                accroupi=false;
                            break;

                            case SDLK_a:
                                attaqueA = false;
                            break;

                            case SDLK_LEFT:
                                marche= false;
                            break;

                            case SDLK_RIGHT:
                                marche= false;
                            break;

                    }
                break;




            }

            action.actionsAutomatique(deltaTime);

            if(courir && !profilGaucheMP) action.actionsClavier('d');
            if(courir && profilGaucheMP) action.actionsClavier('g');

            if(marche && !profilGaucheSP) action.actionsClavier('l');
            if(marche && profilGaucheSP) action.actionsClavier('j');

            
                
        }


            //sprite animé
            Uint32 ticks = SDL_GetTicks();
            Uint32 sprite6 = (ticks / 100) % 6;
            Uint32 sprite8 = (ticks / 100) % 8;



          


            //rectangle destination luffy :
            SDL_Rect rectMPlayer  = {action.MP.getx(), action.MP.gety()  , 140, 150};
            //rectangle destination SP :
            SDL_Rect rectSPlayer  = {action.SP.getx(), action.SP.gety() , 160, 150};

            

            //rectangle source pour luffyCourt :
            SDL_Rect rectCourt = { sprite6 * 150, 0, 145, 150 };
            //rectangle source luffyAccroupi :
            SDL_Rect rectAccroupi= {300, 0, 150, 150};
            //rectangle source luffyAttaque :
            SDL_Rect rectAttaque= {sprite6 * 180, 0, 180, 150};
            //rectangle zoro marche :
            SDL_Rect rectMarche = {sprite8 * 165, 0, 160, 180 };






        
       

    SDL_RenderClear(renderer);  

    //Background
    SDL_RenderCopy(renderer, monImage, NULL,&rectangle );

    //Transparence :
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);


    //chargement de la surface : 
    SDL_Surface *tileset;
    SDL_Texture *texTuile = NULL;
    tileset = IMG_Load("./data/plateforme/2.png");

    //affichage ddes tuiles (plateforme) :
    Afficher(renderer,texTuile,tileset,NOMBRE_BLOCS_LARGEUR,NOMBRE_BLOCS_HAUTEUR);


 



 // a revoir plutard ////////////////////////////////////////////////////////////////////////////////////////

    if (courir && !profilGaucheMP && !accroupi) {SDL_RenderCopy(renderer, texLuffyCourt, &rectCourt, &rectMPlayer); }
        
    else if(courir && profilGaucheMP && !accroupi) { SDL_RenderCopyEx(renderer, texLuffyCourt, &rectCourt, &rectMPlayer, 0, NULL, SDL_FLIP_HORIZONTAL);}

    else if (!courir && profilGaucheMP && !accroupi){ SDL_RenderCopy(renderer, texMPlayerG, NULL,&rectMPlayer );}

    else if (!courir && !profilGaucheMP && !accroupi)  SDL_RenderCopyEx(renderer, texMPlayerG, NULL, &rectMPlayer, 0, NULL, SDL_FLIP_HORIZONTAL);

    else if (!courir && profilGaucheMP && accroupi) { SDL_RenderCopy(renderer, texLuffyAccroupi, &rectAccroupi,&rectMPlayer );}

    else if (!courir && !profilGaucheMP && accroupi) SDL_RenderCopyEx(renderer, texLuffyAccroupi, &rectAccroupi, &rectMPlayer, 0, NULL, SDL_FLIP_HORIZONTAL);

    /* else {
        if(attaqueA)  { SDL_RenderCopy(renderer, texLuffyAttaque, &rectAttaque,&rectMPlayer );}

    } */
    
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////        



    if (marche && !profilGaucheSP ) {SDL_RenderCopy(renderer, texZoroMarche, &rectMarche, &rectSPlayer); }
        
    else if(marche  && profilGaucheSP ) { SDL_RenderCopyEx(renderer, texZoroMarche, &rectMarche, &rectSPlayer, 0, NULL, SDL_FLIP_HORIZONTAL);}

    else if (!marche && profilGaucheSP ){ SDL_RenderCopy(renderer, texSPlayerG, NULL,&rectSPlayer );}

    else if (!marche && !profilGaucheSP )  SDL_RenderCopyEx(renderer, texSPlayerG, NULL, &rectSPlayer, 0, NULL, SDL_FLIP_HORIZONTAL);




        /////////////////////////////////////////////////////////////////////////////////////////////////////////////



        SDL_RenderPresent(renderer);

    }
}









void JeuSDL::boucleAcceuil(){



    // Background Menu

    SDL_Texture* menuBg = loadImage("./data/background/menuBg.jpg");


    // Bouton play

    SDL_Texture * texBPlay= loadImage("./data/Boutons/startBouton.png");
       
    // Bouton parametres

    SDL_Texture * texBParams= loadImage("./data/Boutons/paramsBouton.png");
    
    // Bouton help

    SDL_Texture * texBHelp= loadImage("./data/Boutons/quitBouton.png");

    // Bouton quit

    SDL_Texture * texBQuit= loadImage("./data/Boutons/quitBouton.png");
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

   

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




    SDL_Rect rectangle  = {0, 0, WINDOW_SIZE_WIDTH, WINDOW_SIZE_HIGH};

    SDL_Rect rectPlay = {100,100,250,70};
    SDL_Rect rectHelp = {100,200,250,70};
    SDL_Rect rectParams = {100,300,250,70};
    SDL_Rect rectQuit = {100,400,250,70};



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
                    this -> bouclePartie();                     
                    break;
                };
                break;

                
                case SDL_MOUSEBUTTONDOWN:

                int x = events.button.x ;
                int y = events.button.y ;
                SDL_Point Mouse{x,y};

                if (events.button.button == SDL_BUTTON_LEFT){// Clique Gauche

                    if(SDL_PointInRect(&Mouse, &rectPlay)){

                        this -> bouclePartie();
                    }


                    if(SDL_PointInRect(&Mouse, &rectQuit)){

                        isOpen = false ;
                    }


  
                }
                break;

            }

        }



        
       
        //couleur noire par default
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); 
        SDL_RenderClear(renderer);  

        //Background
        SDL_RenderFillRect(renderer, &rectangle); 
        SDL_RenderCopy(renderer, menuBg, NULL,&rectangle );
        
        //Bouton Play
        SDL_RenderFillRect(renderer, &rectPlay); 
        SDL_RenderCopy(renderer, texBPlay, NULL,&rectPlay);
        //Bouton Settings
        SDL_RenderFillRect(renderer, &rectParams); 
        SDL_RenderCopy(renderer, texBParams, NULL,&rectParams);
        //Bouton Help
        SDL_RenderFillRect(renderer, &rectHelp); 
        SDL_RenderCopy(renderer, texBHelp, NULL,&rectHelp);
        //Bouton Quit
        SDL_RenderFillRect(renderer, &rectQuit); 
        SDL_RenderCopy(renderer, texBQuit, NULL,&rectQuit);
        


        /////////////////////////////////////////////////////////////////////////////////////////
        SDL_RenderPresent(renderer);

    }
}



void JeuSDL::quit(){

    if(NULL != renderer)
        SDL_DestroyRenderer(renderer);
    if(NULL != window)
        SDL_DestroyWindow(window);

   
    SDL_Quit();
    
}


