#include "Terrain.h"
using namespace std ;



terrain ::terrain():dimx(WINDOW_SIZE_WIDTH),dimy(WINDOW_SIZE_HEIGHT){

    for(int x = 0 ;x < dimx; x++){
        
        for(int y = 0; y < dimy; y++){

            caract[x][y]=" ";

        }
    }
}


terrain :: ~terrain(){}

const char* terrain::getXY(int x,int y){ return  this->caract[x][y];}


bool terrain::posisvalide(int x,int y){
    
    if(!(getXY(x,y) =="#") && (x>= 0) && (x<dimx - LARGEUR_SPRITE)&& (y >= 0) && (y<dimx - HAUTEUR_SPRITE)){
    return true;
    }
    else{return false;}
        
} 




int terrain::getDimx(){return this->dimx;}
int terrain::getDimy(){return this->dimy;}

void terrain::setDim(int dimx, int dimy){
    this -> dimx = dimx;
    this -> dimy = dimy;
}

void terrain::setCaract(int x, int y ,const char* caract){
    this->caract[x][y] = caract;
}






Tuiles::Tuiles(){
    width = LARGEUR_TILE;
    height = HAUTEUR_TILE;
    pos = Vector2D(0,0);
    tex.url="./data/plateforme/2.png";
    tex.lettre=" ";
}