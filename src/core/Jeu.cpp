#include "Jeu.h"
using namespace std;



void Jeu :: actionsAutomatique(float deltaTime){
    MP.phy.ticks(deltaTime);
    SP.phy.ticks(deltaTime);

    const float border = WINDOW_SIZE_HEIGHT - HAUTEUR_SPRITE;
	if (MP.phy.getPosy() > border ){

        MP.phy.setPosy(border);
        MP.phy.setVity(0.0f);	
    } 

    if (SP.phy.getPosy() > border ){

        SP.phy.setPosy(border);
        SP.phy.setVity(0.0f);	
    } 
}



void Jeu :: MPClavierDown(int touche, const float deltaTime)
{
  
  switch(touche)
    {
        //MP/////////////////////////////////////////////////////////
        case 0:
            MP.bougerAdroite(500.0f, deltaTime);
            MP.tex.url = "./data/luffy/luffyCourtD.png";//Sprite Courir a corriger
            //MP.tex.isSprite = true;          

        break;     
                            
        case 1: //gauche a inverser
            MP.bougerAgauche(500.0f, deltaTime);
            MP.tex.url = "./data/luffy/luffyCourtG.png";//Sprite Courir
            //MP.tex.isSprite = true;
        break;       

        case 2:
            MP.sauter(600.0f, deltaTime);
            MP.tex.url= "./data/luffy/luffySauteD.png";
            //MP.tex.isSprite = false;
        break;

        case 3 :
            MP.tex.url = "./data/luffy/luffyAccroupiD.png";//Personnage accroupi pour SDL
            MP.tex.lettre = "l";//Personnage accroupi en TXT
            //MP.tex.isSprite = false;
        break;
        

        case 4:
            MP.attaquer(SP);
            MP.tex.url = "./data/luffy/luffyAttaqueA.png"; //attaqueA
            MP.tex.lettre = "LL"; 
            //MP.tex.isSprite = true;
        break;

        case 5:
            MP.attaquer(SP);
            MP.tex.url = "./data/luffy/luffyAttaqueB.png"; //attaqueB
            MP.tex.lettre = "LL";
            //MP.tex.isSprite = true; 
        break;

    }
}


void Jeu::MPClavierUp(int touche, const float deltaTime)
{
        switch(touche)
        {
            case 0:
                MP.tex.url = "./data/luffy/luffyD.png";
                //MP.tex.isSprite = false;
            break;

            case 1:
                MP.tex.url = "./data/luffy/luffyG.png";
                //MP.tex.isSprite = false;
            break; 

            case 2:
        /*     if(MP.phy.getPosx() == ){
                MP.tex.url = 
            } */
            break;

            case 3:

            break;

            case 4:

            break;

            case 5:

            break;
        }
}



void Jeu::SPClavierDown(int touche, const float deltaTime)
{
    switch(touche)
        {
            case 0:
                SP.bougerAgauche(500.0f, deltaTime);     
                SP.tex.url = "./data/zoro/zoroCourtD.png";
                //MP.tex.isSprite = true;
                
            break;

            case 1:
                SP.bougerAdroite(500.0f, deltaTime);     
                SP.tex.url = "./data/zoro/zoroCourtG.png";
                //MP.tex.isSprite = true;
            break; 

            case 2:
                SP.sauter(700.0f, deltaTime);
                SP.tex.url = "./data/zoro/zoroSauteD.png"; 
                //MP.tex.isSprite = false;
            break;

            case 3:
                SP.tex.url = "./data/zoro/zoroAccroupiG.png";
                SP.tex.lettre = "z";
                //MP.tex.isSprite = false;
            break;

            case 4:
                SP.tex.url = "./data/zoro/zoroAttaqueA.png"; //attaqueA
                SP.tex.lettre = "ZZ"; 
                //MP.tex.isSprite = true;
            break;

            case 5:
                SP.tex.url = "./data/zoro/zoroAttaqueB.png"; //attaqueB
                SP.tex.lettre = "ZZ"; 
                //MP.tex.isSprite = true;
            break;
        }
}



void Jeu::SPClavierUp(int touche, const float deltaTime){
        switch(touche)
        {
            case 0:
                SP.tex.url = "./data/zoro/zoroD.png";
                //MP.tex.isSprite = false;
            break;

            case 1:
                SP.tex.url = "./data/zoro/zoroG.png";
                //MP.tex.isSprite = false;
            break; 

            case 2:

            break;

            case 3:

            break;

            case 4:

            break;

            case 5:

            break;
        }
}






    



//but est d'effectuer les actions liés à un clic de souris
// on affectera plus tard le Vector2D aux coordonnés de la souris 
//cela va faire role de gestion de # events du menu 
void Jeu :: actionsMenu(int clic){
    switch(clic){
        //affichage de menu 
        case 0 :
        this-> init();
        break;

        //appuie bouton Play
        case 1 :
        this-> initPartie();
        this-> updatePartie();
        this-> quitPartie();
        break;

     /*    //appuie btn Options
        case 2 :
        
        
        break;

        //appuie btn Help
        case 3 :

        break;

        //appuie btn Quit :
        case 4 :

        break; */

    }
}

//cette fct va servir à initiliser le jeu à savoir : 
//les emplacements de base des boutons => affichage menu 
//les emplacements de base des joueurs
//les textures des joueurs 
//Initialisation du terrain 

void Jeu::initPartie(){
    //initialisation du terrain
    ter1.setDim(30,16);
   
    ter1.tex.url = "./data/background/sunny.jpg"; //SDL
    ter1.tex.lettre="#" ; //TXT

    //initialisation des position et textures des joueurs
    const int MPinitx = LARGEUR_SPRITE ;
    const int MPinity = WINDOW_SIZE_HEIGHT - HAUTEUR_SPRITE ;
    const int SPinitx = WINDOW_SIZE_WIDTH - 2*LARGEUR_SPRITE;
    const int SPinity = WINDOW_SIZE_HEIGHT - HAUTEUR_SPRITE;
   
    MP.phy.setPos(MPinitx,MPinity);
    SP.phy.setPos(SPinitx,SPinity);
   
    MP.tex.url = "./data/luffy/luffyD.png";//Personnage debout
    MP.tex.lettre = "L";//Personnage debout

    SP.tex.url = "./data/zoro/zoroD.png" ; //personnage ZORO debout
    SP.tex.lettre = "Z";//Personnage debout

}

void Jeu::updatePartie(){
 
 



}

void Jeu::quitPartie(){}




//init concerne le menu
void Jeu :: init(){

        menu = Menu(WINDOW_SIZE_WIDTH,WINDOW_SIZE_HEIGHT);

        menu.start.placerBouton(WINDOW_SIZE_WIDTH/7, //placement X par rapport a la page 
                            3*WINDOW_SIZE_HEIGHT/9,
                            WINDOW_SIZE_WIDTH/5,
                            WINDOW_SIZE_HEIGHT/9
                            );

        menu.help.placerBouton(WINDOW_SIZE_WIDTH/7,
                            4*WINDOW_SIZE_HEIGHT/9,
                            WINDOW_SIZE_WIDTH/5,
                            WINDOW_SIZE_HEIGHT/9
                            );


        menu.quit.placerBouton(WINDOW_SIZE_WIDTH/7,
                            5*WINDOW_SIZE_HEIGHT/9,
                            WINDOW_SIZE_WIDTH/5,
                            WINDOW_SIZE_HEIGHT/9
                            );
                            
        menu.back.placerBouton(0,10,10,10);

        menu.tex.url ="./data/background/menuBg.jpg";

        menu.start.tex.url ="./data/Boutons/startBouton.png";
        menu.start.tex.lettre="P";

        menu.quit.tex.url ="./data/Boutons/quitBouton.png";
        menu.quit.tex.lettre="Q";

        menu.back.tex.url ="./data/Boutons/quitBouton.png";
        menu.back.tex.lettre="B";

        this -> initPartie();

}





//libéeration de ttes les donnés du jeu 
//reintialisation des paramètres 
//soit fin de partie ou fermeture de page 
void Jeu::quit(){

}


