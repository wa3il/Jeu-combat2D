#include "Jeu.h"
using namespace std;



void Jeu :: actionsAutomatique(){
    
	if (MP.phy.getPosy() > WINDOW_SIZE_HEIGHT - HAUTEUR_SPRITE){

        MP.phy.setPosy(WINDOW_SIZE_HEIGHT - HAUTEUR_SPRITE);
        MP.phy.setVity(0.0f);	
    } 

    if (SP.phy.getPosy() > WINDOW_SIZE_HEIGHT - HAUTEUR_SPRITE ){

        SP.phy.setPosy(WINDOW_SIZE_HEIGHT - HAUTEUR_SPRITE);
        SP.phy.setVity(0.0f);	
    } 


/* 
        if (MP.phy.getPosx() + LARGEUR_SPRITE <= SP.phy.getPosx()  && 
            MP.phy.getPosx() + LARGEUR_SPRITE > SP.phy.getPosx() + LARGEUR_SPRITE && 
            MP.phy.getPosy() < SP.phy.getPosy() + HAUTEUR_SPRITE &&
            MP.phy.getPosy() + HAUTEUR_SPRITE > SP.phy.getPosy())
                {
                    std::cout<<"ouuiiiiiizegfioef"<<std::endl;
                } */
    

}



void Jeu :: MPClavierDown(int touche)
{
  
  switch(touche)
    {
        //MP/////////////////////////////////////////////////////////
        case 0:
            MP.bougerAdroite(5.0f, ter1);
            MP.tex.url = "./data/luffy/luffyCourtD.png";//Sprite Courir a corriger
            //MP.tex.isSprite = true;          

        break;     
                            
        case 1: //gauche a inverser
            MP.bougerAgauche(5.0f, ter1);
            MP.tex.url = "./data/luffy/luffyCourtG.png";//Sprite Courir
            //MP.tex.isSprite = true;
        break;       

        case 2:                
                MP.sauter(8.0f, ter1);
                MP.tex.url= "./data/luffy/luffySauteD.png";
        break;

        case 3 :
            MP.tex.url = "./data/luffy/luffyAccroupiD.png";//Personnage accroupi pour SDL
            MP.tex.lettre = "l";//Personnage accroupi en TXT
        break;
        

        case 4:
            MP.attaquer(SP);
            MP.tex.url = "./data/luffy/luffyAttaqueA.png"; //attaqueA
            MP.tex.lettre = "LL"; 
            //MP.tex.isSprite = true;
        break;

        case 5:
            MP.attaqueUltime(SP);
            MP.tex.url = "./data/luffy/luffyAttaqueB.png"; //attaqueB
            MP.tex.lettre = "LL";
            //MP.tex.isSprite = true; 
        break;

    }
}


void Jeu::MPClavierUp(int touche)
{
        switch(touche)
        {
            case 0:
                MP.tex.url = "./data/luffy/luffyD.png";
              
            break;

            case 1:
                MP.tex.url = "./data/luffy/luffyG.png";
             
            break; 

            case 2:
            if(MP.phy.getPosy()== WINDOW_SIZE_HEIGHT - HAUTEUR_SPRITE)
                {
                    MP.tex.url = "./data/luffy/luffyD.png";
                }
            break;

            case 3 :
                MP.tex.url = "./data/luffy/luffyD.png";
                MP.tex.lettre = "L";
            break;

            case 4:
                MP.tex.url = "./data/luffy/luffyG.png"; //attaqueA
                //MP.tex.isSprite = true;
            break;

            case 5:
                MP.tex.url = "./data/luffy/luffyG.png"; //attaqueB
            break;
        }
}


void Jeu::SPClavierDown(int touche)
{
    switch(touche)
        {
            case 0:
                SP.bougerAgauche(5.0f, ter1);     
                SP.tex.url = "./data/zoro/zoroCourtD.png";
                //MP.tex.isSprite = true;
                
            break;

            case 1:
                SP.bougerAdroite(5.0f, ter1);     
                SP.tex.url = "./data/zoro/zoroCourtG.png";
                //MP.tex.isSprite = true;
            break; 

            case 2:
                SP.sauter(5.0f, ter1);
                SP.tex.url = "./data/zoro/zoroSauteD.png"; 
                //MP.tex.isSprite = false;
            break;

            case 3:
                SP.tex.url = "./data/zoro/zoroAccroupiG.png";
                SP.tex.lettre = "z";
                //MP.tex.isSprite = false;
            break;

            case 4:
                SP.attaquer(MP);
                SP.tex.url = "./data/zoro/zoroAttaqueA.png"; //attaqueA
                SP.tex.lettre = "ZZ"; 
                //MP.tex.isSprite = true;
            break;

            case 5:
                SP.attaqueUltime(MP);
                SP.tex.url = "./data/zoro/zoroAttaqueB.png"; //attaqueB
                SP.tex.lettre = "ZZ"; 
                //MP.tex.isSprite = true;
            break;
        }
}



void Jeu::SPClavierUp(int touche){
        switch(touche)
        {
            case 0:
                SP.tex.url = "./data/zoro/zoroD.png";
            break;

            case 1:
                SP.tex.url = "./data/zoro/zoroG.png";
            break; 

            case 4 :
                MP.tex.url = "./data/zoro/zoroD.png";
                MP.tex.lettre = "Z";
            break;

            case 5 :
                MP.tex.url = "./data/zoro/zoroD.png";
                MP.tex.lettre = "Z";
            break;
        }
}






    



//cette fct va servir à initiliser le jeu à savoir : 
//les emplacements de base des boutons => affichage menu 
//les emplacements de base des joueurs
//les textures des joueurs 
//Initialisation du terrain 

void Jeu::initPartie(){
    //initialisation du terrain
    ter1.setDim(WINDOW_SIZE_WIDTH,WINDOW_SIZE_HEIGHT);
   
    ter1.tex.url = "./data/background/sunny.jpg"; //SDL
    ter1.tex.lettre="#" ; //TXT

    //initialisation des position et textures des joueurs
    const int MPinitx = LARGEUR_SPRITE ;
    const int MPinity = WINDOW_SIZE_HEIGHT - HAUTEUR_SPRITE ;
    const int SPinitx = WINDOW_SIZE_WIDTH - 2*LARGEUR_SPRITE;
    const int SPinity = WINDOW_SIZE_HEIGHT - HAUTEUR_SPRITE + 20;
   
    MP.phy.setPos(MPinitx,MPinity);
    SP.phy.setPos(SPinitx,SPinity);
   
    MP.tex.url = "./data/luffy/luffyD.png";//Personnage debout
    MP.tex.lettre = "L";//Personnage debout

    SP.tex.url = "./data/zoro/zoroD.png" ; //personnage ZORO debout
    SP.tex.lettre = "Z";//Personnage debout

    // Initialisation des tuiles:
    for(int i=0 ;i<12;i++){
        tuile[i].pos.setx(i*LARGEUR_TILE);
        tuile[i].pos.sety(WINDOW_SIZE_HEIGHT-HAUTEUR_TILE);
        ter1.setCaract(i,WINDOW_SIZE_HEIGHT - HAUTEUR_TILE,"#");
        std::cout <<ter1.getXY(i,WINDOW_SIZE_WIDTH-HAUTEUR_TILE)<<std::endl;

    }

    for (int j=12;j<15;j++){
        tuile[j].pos.setx((j-11) * LARGEUR_TILE);
        tuile[j].pos.sety(WINDOW_SIZE_HEIGHT/2);
        ter1.setCaract(j,WINDOW_SIZE_HEIGHT/4,"#");
    }
    for(int k=15;k<18;k++){
        tuile[k].pos.setx((k-7) * LARGEUR_TILE);
        tuile[k].pos.sety(WINDOW_SIZE_HEIGHT/2);
        ter1.setCaract(k,WINDOW_SIZE_HEIGHT/4, "#");
    }

    for(int l=18;l<24;l++){
        tuile[l].pos.setx((l-15) * LARGEUR_TILE);
        tuile[l].pos.sety(WINDOW_SIZE_HEIGHT/2);
        ter1.setCaract(l, WINDOW_SIZE_HEIGHT/2, "#");

    }
}

void Jeu::updatePartie(float deltaTime){
 
    this->actionsAutomatique();
    MP.phy.ticks(deltaTime); //gravité MP
    SP.phy.ticks(deltaTime); //gravité SP





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

        menu.quit.placerBouton(WINDOW_SIZE_WIDTH/7,
                            5*WINDOW_SIZE_HEIGHT/9,
                            WINDOW_SIZE_WIDTH/5,
                            WINDOW_SIZE_HEIGHT/9
                            );

        menu.son.placerBouton(WINDOW_SIZE_WIDTH-40,0,40,40);
        
        menu.back.placerBouton(0,10,10,10);

        menu.tex.url ="./data/background/menuBg.jpg";

        menu.start.tex.url ="./data/Boutons/startBouton.png";
        menu.start.tex.lettre="Play";

        menu.quit.tex.url ="./data/Boutons/quitBouton.png";
        menu.quit.tex.lettre="Quit";

        menu.son.tex.url ="./data/Boutons/sonOnBouton.jpg";
       

        this -> initPartie();

}





//libéeration de ttes les donnés du jeu 
//reintialisation des paramètres 
//soit fin de partie ou fermeture de page 
void Jeu::quit(){

}


