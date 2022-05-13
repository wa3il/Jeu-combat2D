#include "Jeu.h"
using namespace std;






/*  Jeu::Jeu()
 {
    Personnage MP(0,WINDOW_SIZE_HIGH - HAUTEUR_SPRITE);
    Personnage SP(WINDOW_SIZE_WIDTH,WINDOW_SIZE_HIGH);
    terrain ter1;
 } */


void Jeu:: actionsAutomatique(float deltaTime){
    MP.phy.ticks(deltaTime);
    SP.phy.ticks(deltaTime);

    const float border = WINDOW_SIZE_HEIGHT - HAUTEUR_SPRITE;
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
            cout <<"MP.y =" << MP.phy.getPosy() <<endl;
        break;

        case 't':
            MP.attaquer(SP);
        break;

        case 'j':
            SP.bougerAgauche(10);     
            cout << "SP.x =" << SP.phy.getPosx() <<endl; 
            //profilGaucheSP=true;
        break;

        case 'l':
            SP.bougerAdroite(10);     
            cout << "SP.x =" << SP.phy.getPosx() <<endl;  
            //profilGaucheSP=false;

        break; 

        case 'i':
            SP.sauter(10);
            cout <<"SP.y =" << SP.phy.getPosy() <<endl;
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
//Initialisation du terrain 

void Jeu::initPartie(){
    //initialisation du terrain


    //initialisation des position des joueurs

    const int MPinitx = LARGEUR_SPRITE ;
    const int MPinity = WINDOW_SIZE_HEIGHT - HAUTEUR_SPRITE ;
    const int SPinitx = WINDOW_SIZE_WIDTH - 2*LARGEUR_SPRITE;
    const int SPinity = WINDOW_SIZE_HEIGHT - HAUTEUR_SPRITE;
    MP.phy.setPos(MPinitx,MPinity);
    SP.phy.setPos(SPinitx,SPinity);

}

void Jeu::updatePartie(){
   


}
void Jeu::quitPartie(){}




//init concerne le menu
void Jeu :: init(){

menu = Menu(WINDOW_SIZE_WIDTH,WINDOW_SIZE_HEIGHT);
menu.start.placerBouton(WINDOW_SIZE_WIDTH/7, //placement X par rapport a la page 
                     2*WINDOW_SIZE_HEIGHT/8,
                     WINDOW_SIZE_WIDTH/5,
                     WINDOW_SIZE_HEIGHT/9
                    );

menu.help.placerBouton(WINDOW_SIZE_WIDTH/7,
                     3*WINDOW_SIZE_HEIGHT/8,
                     WINDOW_SIZE_WIDTH/5,
                     WINDOW_SIZE_HEIGHT/9
                    );

menu.options.placerBouton(WINDOW_SIZE_WIDTH/7,
                     4*WINDOW_SIZE_HEIGHT/8,
                     WINDOW_SIZE_WIDTH/5,
                     WINDOW_SIZE_HEIGHT/9
                    );
menu.quit.placerBouton(WINDOW_SIZE_WIDTH/7,
                     5*WINDOW_SIZE_HEIGHT/8,
                     WINDOW_SIZE_WIDTH/5,
                     WINDOW_SIZE_HEIGHT/9
                    );
                    
menu.back.placerBouton(0,10,10,10);
this -> initPartie();

}





//libéeration de ttes les donnés du jeu 
//reintialisation des paramètres 
//soit fin de partie ou fermeture de page 
void Jeu::quit(){

}

//on effectuera plus tard les affecttions pour SDL 
//pour cela il faut rajouter un champ texture pour Menu , Bouton ,Personnage , Terrain
//on affectera ainsi les coord de la souris au champs Vector2D de la fct actions souris 
//pour le clic , on utilisera un booleen qui devient vrai pour l'action , ce booléen 
//correspondera au clic

// ainsi en SDL on aura une boucle d'events pour le init  et carrément une autre boucle
//pour la partie elle meme ou chaque action correspondra au champ renvoyé par les actions. 


