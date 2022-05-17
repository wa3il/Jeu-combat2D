#include "JeuSDL.h"

using namespace std;



JeuSDL::JeuSDL(){};

//fct pour charger des images
SDL_Texture* JeuSDL::loadImage(const char* filename){

    SDL_Surface * image = IMG_Load(filename);

    if(!image)
    {
    cout<<"Erreur de chargement de l'image : "<< filename <<endl;
    }

    return SDL_CreateTextureFromSurface(renderer,image);  //La texture ter1Tex contient maintenant l'image importée
    SDL_FreeSurface(image); //Équivalent du destroyTexture pour les surface, permet de libérer la mémoire quand on n'a plus besoin d'une surface
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




void JeuSDL::init(){

    //Initialisation VIDEO ET AUDIO
     if (0 != SDL_Init(SDL_INIT_VIDEO))  {cout<<"Erreur SDL_Init : "<< SDL_GetError()<<endl; }

    window = SDL_CreateWindow("Anime Fighter", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_SIZE_WIDTH, WINDOW_SIZE_HEIGHT, SDL_WINDOW_SHOWN);

    if(NULL == window)   {  cout<< "Erreur SDL_CreateWindow : "<< SDL_GetError()<<endl; }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if(NULL == renderer)   { cout<<"Erreur SDL_CreateRenderer : "<<SDL_GetError()<<endl; }

    if(TTF_Init()==-1) 
    {
        std::cout<<("TTF_Init: %s\n", TTF_GetError());
        exit(2);
    }

}








void JeuSDL::KeyboardEventsLuffy(bool &isSprite, bool &attaque){

    const Uint8 *state = SDL_GetKeyboardState(NULL);
    
    if(state[SDL_SCANCODE_D]){
        J.MPClavierDown(0);
        isSprite = true; 
        attaque = false;
    }

    else if(state[SDL_SCANCODE_A]){
        J.MPClavierDown(1);
        isSprite = true;
        attaque = false;
    }                           
      
    else if(state[SDL_SCANCODE_W]){
        J.MPClavierDown(2);
        isSprite = false;
        attaque = false;
    }
            
    else if(state[SDL_SCANCODE_S]){
        J.MPClavierDown(3);
        isSprite = false;
        attaque = false;
    }

    else if(state[SDL_SCANCODE_E]){
        J.MPClavierDown(4);
        isSprite = true;
        SDL_Delay(100);
        attaque = true;
    }

    else if(state[SDL_SCANCODE_A]){
        J.MPClavierDown(5);
        isSprite = true;
        attaque = true;
    }
    
    else{
        isSprite = false;
    }

}

void JeuSDL::KeyboardEventsZoro(bool &isSprite, bool &attaque){
    const Uint8 *state = SDL_GetKeyboardState( NULL );
    
    if(state[SDL_SCANCODE_LEFT]){
        J.SPClavierDown(0);
        isSprite = true;
        attaque = false;
    }                  
    else if(state[SDL_SCANCODE_RIGHT]){
        J.SPClavierDown(1);
        isSprite = true;
        attaque = false;    
    }
    else if(state[SDL_SCANCODE_UP]){
        J.SPClavierDown(2);
        isSprite = false;
        attaque = false;

    }
    else if(state[SDL_SCANCODE_DOWN]){
       J.SPClavierDown(3);
       isSprite = false;
       attaque = false;
    }                
    else if(state[SDL_SCANCODE_M]){
        J.SPClavierDown(4);
        isSprite = true;
        attaque = true;
    }
    else if(state[SDL_SCANCODE_N]){
        J.SPClavierDown(5);
        isSprite = true;
        attaque = true;
    }
    else{

        isSprite = false;
        attaque = false;
    }
}

void JeuSDL::MPclavierUP(SDL_Event events, bool &isSprite, bool &attaque){
    switch(events.key.keysym.sym)
        {
            case SDLK_d  : 
                J.MPClavierUp(0);
                isSprite = false;
                attaque = false;
            break;   

            case SDLK_q  : 
                J.MPClavierUp(1);
                isSprite = false;
                attaque = false;
            break;   

            case SDLK_z  : 
                J.MPClavierUp(2);
                isSprite = false; 
                attaque = false;
            break;

            case SDLK_s : 
                J.MPClavierUp(3); 
                isSprite = false;
                attaque = false;
            break;

            case SDLK_e : 
                J.MPClavierUp(4); 
                isSprite = false;
                attaque = false;
            break;

            case SDLK_a  : 
                J.MPClavierUp(5); 
                isSprite = false;
                attaque = false;
            break;


    }
}

void JeuSDL::SPclavierUP(SDL_Event events, bool &isSprite, bool &attaque){
    switch(events.key.keysym.sym)
    {
            case SDLK_LEFT : 
                J.SPClavierUp(0); 
                isSprite =false;
                attaque = false;
            break;
            case SDLK_RIGHT: 
                J.SPClavierUp(1); 
                isSprite =false;
                attaque = false;
            break;
            case SDLK_UP : 
                J.SPClavierUp(2);
                isSprite =false; 
                attaque = false;
            break;
            case SDLK_DOWN : 
                J.SPClavierUp(3); 
                isSprite =false;
                attaque = false;
            break;
            case SDLK_m : 
                J.SPClavierUp(4);
                isSprite =false; 
                attaque = false;
            break;
            case SDLK_n : 
                J.SPClavierUp(5);
                isSprite =false; 
                attaque = false;
            break;
    }
}



void JeuSDL::mainBoucle(){
   
    J.init();
    
    //gestion de la deltatime
    float NOW = clock();
    float LAST = 0;
    float deltaTime = 0;

    

   
    ////chargement de texture
    
    // Background Menu
    SDL_Texture* menuBg = loadImage(J.menu.tex.url);
    
    // Bouton play
    SDL_Texture * texBPlay= loadImage(J.menu.start.tex.url);
    // Bouton quit
    SDL_Texture * texBQuit= loadImage(J.menu.quit.tex.url);
    // Bouton Son
    SDL_Texture * texBSon= loadImage(J.menu.son.tex.url);
    
    //Affectation Boutons a SDLRECT
    SDL_Rect rectPlay   =  convertButtonToSDLRect(J.menu.start);
    SDL_Rect rectQuit   =  convertButtonToSDLRect(J.menu.quit);
    SDL_Rect rectSon   =  convertButtonToSDLRect(J.menu.son);
    SDL_Rect rectBack   =  convertButtonToSDLRect(J.menu.back);

    
    // Background de la partie
    SDL_Texture* ter1Tex = loadImage(J.ter1.tex.url);
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   
    //rectangle bg
    SDL_Rect WinRect  = {0, 0, WINDOW_SIZE_WIDTH, WINDOW_SIZE_HEIGHT};

    //Luffy VS Zoro
    SDL_Texture *texVS = loadImage("./data/vs.png");

    //Rectangle Luffy VS Zoro
    SDL_Rect VS = {400, 0, WINDOW_SIZE_WIDTH - 800, 100 };





    //chargement de la surface des tiles : 

    SDL_Texture * tileset = loadImage("./data/plateforme/2.png");

    SDL_Rect Rect_dest[20] ;

    for(int i=0;i<20;i++)
    {
        Rect_dest[i] = SDL_Rect{J.tuile[i].pos.getx()  * LARGEUR_TILE,
                                J.tuile[i].pos.gety() - HAUTEUR_TILE,
                                LARGEUR_TILE,
                                HAUTEUR_TILE};

    }




   //interupteur :
    bool isOpen = true;
    bool onMenu = true;
    //booleen pour les sprites
    bool isSpriteL = true ;
    bool isSpriteZ = true;
    bool attaqueL = false;
    bool attaqueZ = false;

    
    ////////////////////////////////
   
    SDL_Event events;
    while (isOpen)
    {   
        //sprite animé
        Uint32 ticks = SDL_GetTicks();
        Uint32 nbSprite = (ticks / 100) % 6;

        /* ******** LUFFY ******* */
        //rectangle destination luffy :
        SDL_Rect rectMPlayer  = {J.MP.phy.getPosx(), J.MP.phy.getPosy() , 160, 150};
        //rectangle source pour luffySprite :
        SDL_Rect rectCourt = { nbSprite * 150, NULL, 148, 150 } ;
        //rectangle source luffyAttaque :
        SDL_Rect rectAttaqueLuffy= {nbSprite * 180, NULL, 180, 150};
        //textures
        SDL_Texture * texMP = loadImage(J.MP.tex.url);


        /* ******** ZORO ******* */
        //rectangle destination Zoro :
        SDL_Rect rectSPlayer  = {J.SP.phy.getPosx(), J.SP.phy.getPosy(), 180, 150};
        //rectangle source pour zoroCourt :
        SDL_Rect rectCourtZ = { nbSprite * 190, 0, 180, 150} ;
        //rectangle source ZoroAttaque :
        SDL_Rect rectAttaqueZoro= {nbSprite * 200, 0, 180, 200};
        //textures
        SDL_Texture * texSP = loadImage(J.SP.tex.url);

        //SDL_Texture * texAttaqueZoroA = loadImage("./data/zoro/zoroAttaqueA.png");
        /* SDL_Texture * texAttaqueZoroB = loadImage("./data/zoro/zoroAttaqueB.png") */
        



        /* **********Rectangle Points de vie********** : */
        SDL_Texture * texFeu = loadImage("./data/feu.png");
        SDL_Rect hp_perso_MP ={10, 20, 4*J.MP.getVie(), 30};
        SDL_Rect hp_perso_SP ={WINDOW_SIZE_WIDTH - 410 , 20, 4*J.SP.getVie(), 30};

        SDL_Rect borderMP = {hp_perso_MP.x - 5, hp_perso_MP.y - 5, 410, 40 };
        SDL_Rect borderSP = {hp_perso_SP.x - 5, hp_perso_SP.y - 5, 410, 40 };
        

        //gestion delta time
        LAST = NOW;
        NOW = clock();
        
        float deltaTime = (float)((NOW - LAST)/CLOCKS_PER_SEC);
    
        J.updatePartie(deltaTime);

        while (SDL_PollEvent(&events))
        {
            
            switch (events.type)
            {
                case SDL_QUIT:
                    isOpen = false;
                break;
                
                case SDL_KEYUP:
                    MPclavierUP(events, isSpriteL, attaqueL);
                    SPclavierUP(events, isSpriteZ, attaqueZ);
                break;

                case SDL_MOUSEBUTTONDOWN:

                int x = events.button.x ;
                int y = events.button.y ;
                SDL_Point Mouse{x,y};


                if (events.button.button == SDL_BUTTON_LEFT){// Clique Gauche

                    if(SDL_PointInRect(&Mouse, &rectPlay)){  
                        onMenu = false;
                    }


                    if(SDL_PointInRect(&Mouse, &rectQuit)){
                        isOpen = false ;
                    }

                }
                break;

            }
    
        }
    
        
      
        KeyboardEventsLuffy(isSpriteL, attaqueL);
        KeyboardEventsZoro(isSpriteZ, attaqueZ);



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
            //Bouton Quit
            SDL_RenderCopy(renderer, texBQuit, NULL,&rectQuit);
            //Bouton Son
            SDL_RenderCopy(renderer, texBSon, NULL,&rectSon);
        }
        
        else  
        {

            //Background du Jeu
            SDL_RenderCopy(renderer, ter1Tex, NULL,&WinRect );
        
            //affichage des tuiles (plateforme) :
            for(int i=0 ; i<20;i++)
            {
                SDL_RenderCopy(renderer, tileset, NULL, &Rect_dest[i] );
            }

            //Affichage LUFFY VS ZORO
            SDL_RenderCopy(renderer, texVS, NULL, &VS); 


 

         
            /* LUFFY */
            if(isSpriteL == true && attaqueL == false)
            {
                SDL_RenderCopy(renderer, texMP, &rectCourt ,&rectMPlayer);
            }
            else
            { 
                SDL_RenderCopy(renderer, texMP, NULL,&rectMPlayer);
            }
            

            /* ZORO */
            if(isSpriteZ ==true && attaqueZ == false){
                SDL_RenderCopy(renderer, texSP, &rectCourtZ ,&rectSPlayer);
            }
            else if(isSpriteZ ==false && attaqueZ == false)
            {
                SDL_RenderCopy(renderer, texSP, NULL, &rectSPlayer);
            }

            else if(isSpriteZ==true && attaqueZ == true)
            {
                SDL_RenderCopy(renderer, texSP, &rectAttaqueZoro ,&rectSPlayer);

            }



            //affichage des pv 
            /* barre de HP MP */  
            SDL_SetRenderDrawColor(renderer, 255 - 2.5 * J.MP.getVie(), 2.5 * J.MP.getVie(), 0 ,255);
            SDL_RenderFillRect(renderer, &hp_perso_MP); 

            /* barre de HP SP */
            SDL_SetRenderDrawColor(renderer,255 - 2.5 * J.SP.getVie(),2.5 * J.SP.getVie(), 0,255);    
            SDL_RenderFillRect(renderer, &hp_perso_SP);

            //bordures barre de HP :
            SDL_RenderCopy(renderer, texFeu, NULL, &borderMP);
            SDL_RenderCopy(renderer, texFeu, NULL, &borderSP);
            
            
                       ////////////////////////////////////affichage fin de partie///////////////////////////////////////
            SDL_Rect rectFin = {0,0,WINDOW_SIZE_WIDTH, WINDOW_SIZE_HEIGHT};
            if(!J.MP.estVivant() || !J.SP.estVivant())
            {   
                if(!J.MP.estVivant()){
                    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
                    SDL_RenderFillRect(renderer, &rectFin);
                }
                else {
                    SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255);
                    SDL_RenderFillRect(renderer, &rectFin);
                }

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

    //TTF_Quit();
    SDL_Quit();
    
}
