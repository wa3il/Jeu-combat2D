#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

#include "Texture.h"


class Bouton{
   
    public:

    Bouton();
    
    Texture tex;
    void placerBouton(int x , int y, int w, int h);
    int getx()const ;
    int gety()const ;
    int getw()const ;
    int geth()const ;
    
    private:
    int b_x,b_y;
    int b_w,b_h;

    enum etatBouton{
        Pressed = 0,
        Released = 1
    };
};


class Menu{
   
    public:
    Menu();
    Menu(int w , int h);
    
    Texture tex;
    
    Bouton start;
    Bouton quit;
    Bouton back;
    Bouton son;
    private:
    int m_w , m_h ;
    
   
};






#endif