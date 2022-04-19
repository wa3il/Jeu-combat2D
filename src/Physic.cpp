#include "Physic.h"


Physic::Physic(){
    m_position = Vector2D();
    m_vitesse = Vector2D();
    m_acceleration = Vector2D();
}

Physic::Physic(int posx,int posy)
{
    m_position = Vector2D(posx,posy);
    m_vitesse = Vector2D(0,0);
    m_acceleration = Vector2D(0,0);
}

Physic::~Physic(){
}

void Physic::ticks(){
    m_acceleration.sety(1);

    m_vitesse += m_acceleration;

    m_position += m_vitesse; 
}

Vector2D Physic::getPos() const{ return m_position; }
Vector2D Physic::getVit() const{ return m_vitesse; }

int Physic::getPosx() const{ return m_position.getx(); }
int Physic::getPosy() const{ return m_position.gety(); }

void Physic::setPos(int x, int y){
     m_position.setx(x);
     m_position.sety(y);
     }

void Physic::setPosx(int x){
    m_position.setx(x);
}

void Physic::setPosy(int y){
    m_position.sety(y);

}


void Physic::setVitx(int x){
    m_vitesse.setx(x);
}
void Physic::setVity(int y){
    m_vitesse.sety(y);
}