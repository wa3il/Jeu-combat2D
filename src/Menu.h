#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>




class Bouton{
   
    public:

    Bouton();

   
    void placerBouton(int x , int y, int w, int h);
    

    private:
    int b_x,b_y;
    int b_w,b_h;
    enum etatBouton{
        Pressed = 0;
        Released = 1:
    }
};


class Menu{
   
    public:
    Menu();
    Menu(int w , int h);
    


    private:
    int m_w , m_h ;
    Bouton start;
    Bouton quit;
    Bouton back;
   
};






#endif