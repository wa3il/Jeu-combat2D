#include "Physic.h"

//Constructeur Destructeur
Physic::Physic(){
    m_position = Vector2D();
    m_vitesse = Vector2D();
    m_acceleration = Vector2D();
}


Physic::~Physic(){}



//position 
Vector2D Physic::getPos() const{ return m_position; }

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



//vitesse
Vector2D Physic::getVit() const{ return m_vitesse; }

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



//gravité

void Physic::ticks(float deltaTime){//tirer le personnage vers le bas

    m_acceleration.sety(1);

    m_vitesse += m_acceleration * deltaTime;

    m_position += m_vitesse * deltaTime; 

}

///////////////////////////////////
//test Collision
bool Physic::PointRect(const Vector2D &p, const Rect &r){

    return (p.getx() >= r.getx() && p.gety() >= r.gety() && p.getx() < r.getx() + r.getw() && p.gety() < r.gety() + r.geth());
}

