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

void Physic::ticks(float deltaTime){

    m_acceleration.sety(1);

    m_vitesse += m_acceleration * deltaTime;

    m_position += m_vitesse * deltaTime; 

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

void Physic::setVit(int x, int y){
    m_vitesse.setx(x);
    m_vitesse.sety(y);

}



void Physic::setVitx(int x){
    m_vitesse.setx(x);
}
void Physic::setVity(int y){
    m_vitesse.sety(y);
}


bool Physic::PointRect(const Vector2D &p, const Rect &r){

    return (p.getx() >= r.getx() && p.gety() >= r.gety() && p.getx() < r.getx() + r.getw() && p.gety() < r.gety() + r.geth());
}

