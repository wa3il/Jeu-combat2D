#include "terrain.h"

terrain ::terrain():dimx(60),dimy(20){
    for(int y=0;y<dimy-1;y++){
        for(int x=0;x<dimx;x++){
            ter[y][x]='_';
        }
    }
    for(int x=0;x<dimx;x++){
        ter[dimy-1][x]='#';
    }}
terrain ::terrain(int x,int y):dimx(x),dimy(y){
    for(int y=0;y<dimy-1;y++){
        for(int x=0;x<dimx;x++){
            ter[y][x]='_';
        }
    }
    for(int x=0;x<dimx;x++){
        ter[dimy-1][x]='#';
    }
    ;}

terrain :: ~terrain(){}

char terrain::getXY(int x,int y){ return ter[y][x];}

bool terrain::posisvalide(int x,int y){
     return ((ter[x][y] != '#') && (x>= 0) && (x<dimx)&& (y >= 0) && (y<dimx));
}

int terrain::getDimx(){return dimx;}
int terrain::getDimy(){return dimy;}

