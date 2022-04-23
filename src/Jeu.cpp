#include "Jeu.h"
using namespace std;






/*  Jeu::Jeu()
 {
    Personnage MP(0,WINDOW_SIZE_HIGH - HAUTEUR_SPRITE1);
    Personnage SP(WINDOW_SIZE_WIDTH,WINDOW_SIZE_HIGH);
    terrain ter1;
 } */


void Jeu:: actionsAutomatique(float deltaTime){
    MP.ticks(deltaTime);
    SP.ticks(deltaTime);


    //position luffy : main player
    MP.phy.setVity(WINDOW_SIZE_HIGH - HAUTEUR_SPRITE1);

    //position ichigo : Second player
    SP.phy.setVity(500);
    //SP.phy.setPosx(WINDOW_SIZE_WIDTH - LARGEUR_SPRITE1);


    const float border = WINDOW_SIZE_HIGH - HAUTEUR_SPRITE1;
	if (MP.phy.getPosy() > border ){

        MP.phy.setPosy(border);
        MP.phy.setVity(0);	
    } 

    if (SP.phy.getPosy() > border ){

        SP.phy.setPosy(border);
        SP.phy.setVity(0);	
    } 
}

void Jeu :: actionsClavier(const char touche){

  switch(touche)
    {

        case 'd':
            MP.bougerAdroite(10);
            //cout <<"MP.x =" << MP.getx() <<endl; 
            //profilGaucheMP=false;
        break;     
                            
        case 'g':
            MP.bougerAgauche(10);
            //cout << "MP.x =" << MP.getx() <<endl;  
            //profilGaucheMP=true;    
        break;       

        case 'z':
            MP.sauter(200);
            cout <<"MP.y =" << MP.gety() <<endl;
        break;

        case 't':
            MP.attaquer(SP);
        break;

        case 'j':
            SP.bougerAgauche(10);     
            cout << "SP.x =" << SP.getx() <<endl; 
            //profilGaucheSP=true;
        break;

        case 'l':
            SP.bougerAdroite(10);     
            cout << "SP.x =" << SP.getx() <<endl;  
            //profilGaucheSP=false;

        break; 

        case 'i':
            SP.sauter(10);
            cout <<"SP.y =" << SP.gety() <<endl;
        break;


    }

}

