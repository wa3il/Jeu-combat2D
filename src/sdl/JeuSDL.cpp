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
    bool isSprite = false ;
    ///////////////////

    SDL_Event events;
    
    while (isOpen)
    {   

      
      
        //sprite animé
        Uint32 ticks = SDL_GetTicks();
        Uint32 nbSprite = (ticks / 100) % 6;

                            /* ******** LUFFY ******* */

        //rectangle destination luffy :
        SDL_Rect rectMPlayer  = {J.MP.phy.getPosx(), J.MP.phy.getPosy()  , 160, 150};
        //rectangle source pour luffySprite :
        SDL_Rect rectCourt = { nbSprite * 150, NULL, 148, 150 } ;

        //rectangle source luffyAttaque :
        SDL_Rect rectAttaque= {nbSprite * 180, NULL, 180, 150};

        //textures
        SDL_Texture * texMP = loadImage(J.MP.tex.url);



                            /* ******** ZORO ******* */

        
        //rectangle destination Zoro :
        SDL_Rect rectSPlayer  = {J.SP.phy.getPosx(), J.SP.phy.getPosy() , 180, 155};
        //rectangle source pour zoroCourt :
        SDL_Rect rectCourtZ = { nbSprite * 190, 0, 180, 150} ;
        //textures
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
                    J.MPClavierDown(0, deltaTime);
                    isSprite = true;
                    break;    
                                
                    case SDLK_q:
                    J.MPClavierDown(1, deltaTime);
                    isSprite = true;
                    break;       

                    case SDLK_z:
                    J.MPClavierDown(2, deltaTime);
                    break;
            
                    case SDLK_s:
                    J.MPClavierDown(3, deltaTime);
                    break;

                    case SDLK_y:
                    J.MPClavierDown(4, deltaTime);
                    break;

                    case SDLK_u:
                    J.MPClavierDown(5, deltaTime);
                    break;


                    case SDLK_LEFT:
                    J.SPClavierDown(0, deltaTime);
                    break;

                    case SDLK_RIGHT:
                    J.SPClavierDown(1, deltaTime);
                    break;

                    case SDLK_UP:
                    J.SPClavierDown(2, deltaTime);
                    break;

                    case SDLK_DOWN:
                    J.SPClavierDown(3, deltaTime);
                    break;

                    case SDLK_b:
                    J.SPClavierDown(4, deltaTime);
                    break;

                    case SDLK_n:
                    J.SPClavierDown(5, deltaTime);
                    break;

                }
                break;
                
                case SDL_KEYUP:
                 switch(events.key.keysym.sym)
                 {
                    case SDLK_d:
                        J.MPClavierUp(0, deltaTime);
                    break;    
                                
                    case SDLK_q:
                        J.MPClavierUp(1, deltaTime);
                    break;       

                    case SDLK_z:
                        J.MPClavierUp(2, deltaTime);
                    break;
            
                    case SDLK_s:
                        J.MPClavierUp(3, deltaTime);                  
                    break;

                    case SDLK_y:
                        J.MPClavierUp(4, deltaTime);
                    break;

                    case SDLK_u:
                        J.MPClavierUp(4, deltaTime);                    
                    break;


                    case SDLK_LEFT:
                        J.SPClavierUp(0, deltaTime);
                    break;

                    case SDLK_RIGHT:
                        J.SPClavierUp(1, deltaTime);                  
                    break;

                    case SDLK_UP:
                        J.SPClavierUp(2, deltaTime);                                     
                    break;

                    case SDLK_DOWN:
                        J.SPClavierUp(3, deltaTime);                                      
                    break;

                    case SDLK_b:
                        J.SPClavierUp(4, deltaTime);                                     
                    break;

                    case SDLK_n:
                        J.SPClavierUp(5, deltaTime);                                 
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
        
        if(onMenu)
        {
            //Background for menu
            SDL_RenderCopy(renderer, menuBg, NULL,&WinRect );
            
            //Bouton Play
            SDL_RenderCopy(renderer, texBPlay, NULL,&rectPlay);
            //Bouton Help
            SDL_RenderCopy(renderer, texBHelp, NULL,&rectHelp);
            //Bouton Quit
            SDL_RenderCopy(renderer, texBQuit, NULL,&rectQuit);
        }
        
        else
        {

            //Background du Jeu
            SDL_RenderCopy(renderer, ter1Tex, NULL,&WinRect );
        
            //affichage des tuiles (plateforme) :
            Afficher(renderer,texTuile,tileset,NOMBRE_BLOCS_LARGEUR,NOMBRE_BLOCS_HAUTEUR);
            

            if(isSprite == true)
            {
                SDL_RenderCopy(renderer, texMP, &rectCourt ,&rectMPlayer);
            }
            else
            {
                SDL_RenderCopy(renderer, texMP, NULL,&rectMPlayer);
            }
            


            if(isSprite == true)
            {
                SDL_RenderCopy(renderer, texSP, &rectCourtZ ,&rectSPlayer);
            }
            else
            {
                SDL_RenderCopy(renderer, texSP, NULL, &rectSPlayer);
            }
        }
      
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


