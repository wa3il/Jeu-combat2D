#include "terrain.h"





   const char ter1[18][15] = {
    "0000000000000",
    "0000000000000",
    "0000000000000",
    "0000000000000",
    "0000000000000",
    "0000000000000",
    "0000000000000",
    "0000000000000",
    "0000000000000",
    "0000000000000",
    "0000000000000",
    "0000000000000",
    "0000000000000",
    "0000000000000",
    "0000000000000",
    "0000000000000",
    "0000000000000",
    "#############"};


terrain ::terrain():dimx(18),dimy(15){

    for(int x = 0 ;x < dimx; x++){
        
        for(int y = 0; y < dimy; y++){

            ter[x][y]=ter1[x][y];
            std::cout<<ter1[x][y]<<std::endl;

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

