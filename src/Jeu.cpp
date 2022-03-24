#include "Jeu.h"
using namespace std;

void Jeu :: actionsClavier(const char touche){

  switch(touche)
    {

        case 'd':
            MP.bougerAdroite(10);
            cout <<"MP.x =" << MP.getx() <<endl; 
            //profilGaucheMP=false;
        break;    
                            
        case 'g':
            MP.bougerAgauche(10);
            cout << "MP.x =" << MP.getx() <<endl;  
            //profilGaucheMP=true;    
        break;       

        case 'z':
            MP.sauter(10);
            cout <<"MP.y =" << MP.gety() <<endl;
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