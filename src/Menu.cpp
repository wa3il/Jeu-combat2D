#include "Menu.h"

using namespace std;


Bouton::Bouton() : b_x(0),b_y(0),b_w(30),b_h(20)
{}


Menu::Menu() : m_w(200),m_h(200)
{}

Menu::Menu(int w,int h) : m_w(w),m_h(h)
{}

void Bouton::placerBouton(int x , int y, int w, int h){
    b_x = x;
    b_y = y;
    b_w = w;
    b_h = h;
}