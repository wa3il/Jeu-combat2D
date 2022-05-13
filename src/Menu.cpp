#include "Menu.h"

using namespace std;


Bouton::Bouton() : b_x(0),b_y(0),b_w(0),b_h(0)
{}



Menu::Menu() : m_w(1200),m_h(650)
{}

Menu::Menu(int w,int h) : m_w(w),m_h(h)
{}

void Bouton::placerBouton(int x , int y, int w, int h){
    this-> b_x = x;
    this->b_y = y;
    this->b_w = w;
    this->b_h = h;
}

int Bouton::getx()const{
    return this-> b_x;
}

int Bouton::gety()const{
    return this-> b_y;
}

int Bouton::getw()const{
    return this-> b_w;
}

int Bouton::geth()const{
    return this-> b_h;
}