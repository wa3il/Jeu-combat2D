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

float Physic::getPosx() const{ return m_position.getx(); }
float Physic::getPosy() const{ return m_position.gety(); }

void Physic::setPos(float x, float y){
     m_position.setx(x);
     m_position.sety(y);
    }

void Physic::setPosx(float x){
    m_position.setx(x);
}

void Physic::setPosy(float y){
    m_position.sety(y);

}



//vitesse
Vector2D Physic::getVit() const{ return m_vitesse; }

void Physic::setVit(float x, float y){
    m_vitesse.setx(x);
    m_vitesse.sety(y);
}

void Physic::setVitx(float x){
    m_vitesse.setx(x);
}
void Physic::setVity(float y){
    m_vitesse.sety(y);
}




void Physic::setAccy(float y)
{
    this->m_acceleration.sety(y);
}


//gravité

void Physic::ticks(const float deltaTime){//tirer le personnage vers le bas

    m_acceleration.sety(300.0);

    m_vitesse += m_acceleration * deltaTime;

    m_position += m_vitesse * deltaTime; 

}



