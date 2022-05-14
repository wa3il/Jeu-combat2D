#include "JeuSDL.h"

using namespace std;









JeuSDL::JeuSDL(){};

//fct pour charger des images
SDL_Texture* JeuSDL::loadImage(const char* filename){

    SDL_Surface * image = IMG_Load(filename);

    if(!image)
    {
    cout<<"Erreur de chargement de l'image : "<< SDL_GetError()<<endl;
    }

    return SDL_CreateTextureFromSurface(renderer,image);  //La texture ter1Tex contient maintenant l'image importée
    SDL_FreeSurface(image); //Équivalent du destroyTexture pour les surface, permet de libérer la mémoire quand on n'a plus besoin d'une surface
}


void JeuSDL::init(){
     if (0 != SDL_Init(SDL_INIT_VIDEO))  {cout<<"Erreur SDL_Init : "<< SDL_GetError()<<endl; }

     window = SDL_CreateWindow("SDL2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_SIZE_WIDTH, WINDOW_SIZE_HEIGHT, SDL_WINDOW_SHOWN);

    if(NULL == window)   {  cout<< "Erreur SDL_CreateWindow : "<< SDL_GetError()<<endl; }

        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if(NULL == renderer)   { cout<<"Erreur SDL_CreateRenderer : "<<SDL_GetError()<<endl; }

     
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
            if(J.ter1.getXY(i,j) == '#') {
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


SDL_Rect convertRectToSDLRect(Rect monRect){

    return SDL_Rect{monRect.getx(),
                    monRect.gety(),
                    monRect.getw(),
                    monRect.geth()};
}

SDL_Rect convertButtonToSDLRect(Bouton monbtn){

    return SDL_Rect{monbtn.getx(),
                    monbtn.gety(),
                    monbtn.getw(),
                    monbtn.geth()};
}



void JeuSDL::boucleAcceuil(){
   
    J.init();
    
    float NOW = clock();
    float LAST = 0;
    float deltaTime = 0;


    ////chargement de texture
    
    // Background Menu
    SDL_Texture* menuBg = loadImage(J.menu.tex.url);
    // Bouton play
    SDL_Texture * texBPlay= loadImage(J.menu.start.tex.url);
    // Bouton help
    SDL_Texture * texBHelp= loadImage(J.menu.help.tex.url);
    // Bouton quit
    SDL_Texture * texBQuit= loadImage(J.menu.quit.tex.url);
   
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Background de la partie
    SDL_Texture* ter1Tex = loadImage(J.ter1.tex.url);
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   

   
    ////////////////////////////////////////////////////////////////////////////////////////////
    //chargement de la surface des tiles : 
    SDL_Surface *tileset;
    SDL_Texture *texTuile = NULL;
    tileset = IMG_Load("./data/plateforme/2.png");
    /////////////////////////////////////////////////////////////////
   
    //rectangle bg
    SDL_Rect WinRect  = {0, 0, WINDOW_SIZE_WIDTH, WINDOW_SIZE_HEIGHT};
    
    //Affectation Boutons a SDLRECT
    SDL_Rect rectPlay   =  convertButtonToSDLRect(J.menu.start);
    SDL_Rect rectHelp   =  convertButtonToSDLRect(J.menu.help);
    SDL_Rect rectParams =  convertButtonToSDLRect(J.menu.options);
    SDL_Rect rectQuit   =  convertButtonToSDLRect(J.menu.quit);
    SDL_Rect rectBack   =  convertButtonToSDLRect(J.menu.back);

   

  //interupteur :
    bool isOpen = true;
    bool onMenu = true;
    bool isSprite = false;
    ///////////////////

    SDL_Event events;
    
    while (isOpen)
    {   
        //rectangle destination luffy :
        SDL_Rect rectMPlayer  = {J.MP.phy.getPosx(), J.MP.phy.getPosy()  , 140, 150};
        //rectangle destination Zoro :
        SDL_Rect rectSPlayer  = {J.SP.phy.getPosx(), J.SP.phy.getPosy() , 160, 150};
      
      
        //sprite animé
        Uint32 ticks = SDL_GetTicks();
        Uint32 sprite6 = (ticks / 100) % 6;
        Uint32 sprite8 = (ticks / 100) % 8;     

        //rectangle source pour luffySprite :
        SDL_Rect rectCourt = { sprite6 * 150, 0, 145, 150 } ;

        //rectangle source luffyAttaque :
        SDL_Rect rectAttaque= {sprite6 * 180, 0, 180, 150};
        
        //rectangle zoro marche :
        SDL_Rect rectMarche = {sprite8 * 165, 0, 160, 150 }; 
        
        
        //textures des personnages

        SDL_Texture * texMP = loadImage(J.MP.tex.url);
  
        SDL_Texture * texSP = loadImage(J.SP.tex.url);
  
     

        
        
        
        //gestion delta time
        LAST = NOW;
        NOW = clock();
        float deltaTime = (float)((NOW - LAST)/CLOCKS_PER_SEC);
        J.actionsAutomatique(deltaTime);

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
                    J.actionsClavier('d',deltaTime);
                    isSprite = true;
                    break;    
                                
                    case SDLK_q:
                    J.actionsClavier('g',deltaTime);
                    break;       

                    case SDLK_z:
                    J.actionsClavier('z',deltaTime);
                    break;
            
                    case SDLK_s:
                    J.actionsClavier('s',deltaTime);
                    break;

                    case SDLK_y:
                    J.actionsClavier('t', deltaTime);
                    break;

                    case SDLK_u:
                    J.actionsClavier('w', deltaTime);
                    break;


                    case SDLK_LEFT:
                    J.actionsClavier('j', deltaTime);
                    break;

                    case SDLK_RIGHT:
                    J.actionsClavier('l', deltaTime);
                    break;

                    case SDLK_UP:
                    J.actionsClavier('i', deltaTime);
                    break;

                    case SDLK_DOWN:
                    J.actionsClavier('k', deltaTime);
                    break;

                    case SDLK_b:
                    J.actionsClavier('b', deltaTime);
                    break;

                    case SDLK_n:
                    J.actionsClavier('n', deltaTime);
                    break;

                };
                break;
                
                case SDL_KEYUP:
                 switch(events.key.keysym.sym)
                 {
                     case SDLK_d:
                  
                    break;    
                                
                    case SDLK_q:
                  
                    break;       

                    case SDLK_z:
                  
                    break;
            
                    case SDLK_s:
                  
                    break;

                    case SDLK_y:
                   
                    break;

                    case SDLK_u:
                    
                    break;


                    case SDLK_LEFT:
                    
                    break;

                    case SDLK_RIGHT:
                   
                    break;

                    case SDLK_UP:
                   
                    break;

                    case SDLK_DOWN:
                    
                    break;

                    case SDLK_b:
                   
                    break;

                    case SDLK_n:
               
                    break;

                    }
                break;

                
                case SDL_MOUSEBUTTONDOWN:

                int x = events.button.x ;
                int y = events.button.y ;
                SDL_Point Mouse{x,y};


                if (events.button.button == SDL_BUTTON_LEFT){// Clique Gauche

                    if(SDL_PointInRect(&Mouse, &rectPlay)){  
                        J.actionsMenu(1);
                        onMenu = false;
                    }


                    if(SDL_PointInRect(&Mouse, &rectQuit)){

                        isOpen = false ;
                    }

                }
                break;

            }

        }


        SDL_RenderClear(renderer);  
    
        //Transparence :
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
        SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
        SDL_RenderFillRect(renderer, &WinRect); 
        
        if(onMenu){
            //Background for menu
            SDL_RenderCopy(renderer, menuBg, NULL,&WinRect );
            
            //Bouton Play
            SDL_RenderFillRect(renderer, &rectPlay); 
            SDL_RenderCopy(renderer, texBPlay, NULL,&rectPlay);
            //Bouton Help
            SDL_RenderFillRect(renderer, &rectHelp); 
            SDL_RenderCopy(renderer, texBHelp, NULL,&rectHelp);
            //Bouton Quit
            SDL_RenderFillRect(renderer, &rectQuit); 
            SDL_RenderCopy(renderer, texBQuit, NULL,&rectQuit);
        }
        
        else{

            //Background du Jeu
            SDL_RenderCopy(renderer, ter1Tex, NULL,&WinRect );
        
            //affichage des tuiles (plateforme) :
            Afficher(renderer,texTuile,tileset,NOMBRE_BLOCS_LARGEUR,NOMBRE_BLOCS_HAUTEUR);
            
            //Bouton Play
            SDL_RenderFillRect(renderer, &rectMPlayer); 
            if(isSprite == true){
                SDL_RenderCopy(renderer, texMP, &rectCourt ,&rectMPlayer);
            }
            else{
                SDL_RenderCopy(renderer, texMP, NULL,&rectMPlayer);
            }
            
            //Bouton Settings
            SDL_RenderFillRect(renderer, &rectSPlayer); 
            SDL_RenderCopy(renderer, texSP, NULL,&rectSPlayer);
        }
      
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


