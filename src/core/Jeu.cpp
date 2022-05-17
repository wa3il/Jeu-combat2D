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



for(int i=12; i<20; i++) {
	if((MP.phy.getPosy() + HAUTEUR_SPRITE < tuile[i].pos.gety() + 10) && 
        (MP.phy.getPosx() + LARGEUR_SPRITE  > tuile[12].pos.getx() * LARGEUR_TILE  &&
        MP.phy.getPosx() < tuile[19].pos.getx() * LARGEUR_TILE)) 

    {  
        
        MP.phy.setPosy(tuile[i].pos.gety() - HAUTEUR_SPRITE );
        MP.phy.setVity(0.0f);
    }

}

for(int i=12; i<20; i++) {
	if((SP.phy.getPosy() + HAUTEUR_SPRITE < tuile[i].pos.gety() + 10) && 
        (SP.phy.getPosx()  > tuile[12].pos.getx() * LARGEUR_TILE  &&
        SP.phy.getPosx() < tuile[19].pos.getx() * LARGEUR_TILE)) 

    {  
        
        SP.phy.setPosy(tuile[i].pos.gety() - (HAUTEUR_SPRITE+HAUTEUR_TILE) );
        SP.phy.setVity(0.0f);
    }
}

/*     else if(MP.phy.getPosy() > tuile[15].pos.gety()) MP.phy.setPosy(500); */

    

    

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
            MP.bougerAdroite(ter1);
            MP.tex.url = "./data/luffy/luffyCourtD.png";//Sprite Courir a corriger

        break;     
                            
        case 1: //gauche a inverser
            MP.bougerAgauche(ter1);
            MP.tex.url = "./data/luffy/luffyCourtG.png";//Sprite Courir
        break;       

        case 2:    
                MP.phy.setPosy(MP.phy.getPosy()+0.5)        ;    
                MP.sauter(ter1);
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
        break;

        case 5:
            MP.attaqueUltime(SP);
            MP.tex.url = "./data/luffy/luffyAttaqueB.png"; //attaqueB
            MP.tex.lettre = "LL";
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
                MP.phy.setPosy(MP.phy.getPosy() + 1);
            break;

            case 4:
                MP.tex.url = "./data/luffy/luffyG.png"; //attaqueA
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
                SP.bougerAgauche(ter1);     
                SP.tex.url = "./data/zoro/zoroCourtD.png";
                
            break;

            case 1:
                SP.bougerAdroite(ter1);     
                SP.tex.url = "./data/zoro/zoroCourtG.png";
            break; 

            case 2:
                SP.phy.setPosy(SP.phy.getPosy()+1)        ;  
                SP.sauter(ter1);
                SP.tex.url = "./data/zoro/zoroSauteD.png"; 
            break;

            case 3:
                SP.tex.url = "./data/zoro/zoroAccroupiG.png";
                SP.tex.lettre = "z";
            break;

            case 4:
                SP.attaquer(MP);
                SP.tex.url = "./data/zoro/zoroAttaqueA.png"; //attaqueA
                SP.tex.lettre = "ZZ"; 
            break;

            case 5:
                SP.attaqueUltime(MP);
                SP.bougerAgauche(ter1);
                SP.tex.url = "./data/zoro/zoroAttaqueB.png"; //attaqueB
                SP.tex.lettre = "ZZ"; 
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

            case 3:
                SP.tex.url = "./data/zoro/zoroG.png";
                SP.tex.lettre = "Z";
                SP.phy.setPosy(SP.phy.getPosy() + 1);
            break;

            case 4 :
                SP.tex.url = "./data/zoro/zoroD.png";
                SP.tex.lettre = "Z";
            break;

            case 5 :
                SP.tex.url = "./data/zoro/zoroD.png";
                SP.tex.lettre = "Z";
            break;
        }
}






    



//cette fct va servir à initiliser le jeu à savoir : 
//les emplacements de base des boutons => affichage menu 
//les emplacements de base des joueurs
//les textures des joueurs 
//Initialisation du terrain 

void Jeu::initPartie(){

   
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
        tuile[i].pos.setx(i);
        tuile[i].pos.sety(ter1.getDimy());
        ter1.setCaract(i, ter1.getDimy(),"#");
        //std::cout <<ter1.getXY(i,WINDOW_SIZE_WIDTH-HAUTEUR_TILE)<<std::endl;

    }

    //platforme
    for (int j=12;j<20;j++){
        tuile[j].pos.setx((j-10));
        tuile[j].pos.sety(ter1.getDimy()/2);
        ter1.setCaract(j,ter1.getDimy()/2,"#");
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

        //initialisation du terrain
        ter1.setDim(WINDOW_SIZE_WIDTH,WINDOW_SIZE_HEIGHT);

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


