#include "Terrain.h"



   const char ter1[10][58] = {
    "00000000000000000000000000000000000000000000000000000000",
    "00000000000000000000000000000000000000000000000000000000",
    "00000000000000000000000000000000000000000000000000000000",
    "00000000000000000000000000000000000000000000000000000000",
    "00000000000000000000000000000000000000000000000000000000",
    "0000000##############00000000000000000000000000000000000",
    "00000000000000000000000000000000000000000000000000000000",
    "00000000000000000000000000000000000000000000000000000000",
    "00000000000000000000000000000000000000000000000000000000",
    "########################################################"};

terrain ::terrain():dimx(10),dimy(58)
{

    for(int x = 0 ;x < dimx; x++){
        
        for(int y = 0; y < dimy; y++){

            ter[x][y]=ter1[x][y];
            //std::cout<<ter1[x][y]<<std::endl;

        }
    }
}


terrain :: ~terrain(){}

char terrain::getXY(int x,int y){ return this->ter[x][y];}

bool terrain::posisvalide(int x,int y){
     return ((ter[x][y] != '#') && (x>= 0) && (x<=dimx)&& (y >= 0) && (y<=dimx));
}

int terrain::getDimx(){return this->dimx;}
int terrain::getDimy(){return this->dimy;}

void terrain::setDim(int dimx, int dimy){
    this -> dimx = dimx;
    this -> dimy = dimy;
}


