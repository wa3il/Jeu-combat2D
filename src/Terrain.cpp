#include "Terrain.h"
#include "Constantes.h"




   const char ter1[30][16] = {
    "00000000000000",
    "00000000000000",
    "00000000000000",
    "00000000000000",
    "00000000000000",
    "00000000000000",
    "00000000000000",
    "0000######0000",
    "00000000000000",
    "00000000000000",
    "00000000000000",
    "00000000000000",
    "000########000",
    "00000000000000",
    "00000000000000",
    "00000000000000",
    "####0000000000",
    "00000000000000",
    "00000000000000",
    "00000000000000",
    "00000000000000",
    "00000000000000",
    "00000000000000",
    "00000000000000",
    "00000000000000",
    "00000000000000",
    "00000000000000",
    "00000000000000",
    "00000000000000",
    "##############"};


terrain ::terrain():dimx(30),dimy(16){

    for(int x = 0 ;x < dimx; x++){
        
        for(int y = 0; y < dimy; y++){

            ter[x][y]=ter1[x][y];
            //std::cout<<ter1[x][y]<<std::endl;

        }
    }
}


terrain :: ~terrain(){}

char terrain::getXY(int x,int y){ return ter[x][y];}

bool terrain::posisvalide(int x,int y){
     return ((ter[x][y] != '#') && (x>= 0) && (x<dimx)&& (y >= 0) && (y<dimx));
}

int terrain::getDimx(){return dimx;}
int terrain::getDimy(){return dimy;}

void terrain::setDim(int dimx, int dimy){
    this -> dimx = dimx;
    this -> dimy = dimy;
}

