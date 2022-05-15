#ifndef PHYSIC_H
#define PHYSIC_H

#include "Vector2D.h"
#include <time.h>

class Physic
{
private:
    Vector2D m_position;
    Vector2D m_vitesse;
    Vector2D m_acceleration;
    

public:
    Physic();
    ~Physic();

   // float t ;//time

    Vector2D getPos() const;
    float getPosx() const;
    float getPosy() const;

    void setPos(float x, float y);
    void setPosx(float x);
    void setPosy(float y);

    Vector2D getVit() const;
    void setVit(float x, float y);
    void setVitx(float x);
    void setVity(float y);

    void ticks(const float deltaTime);//gravité

    bool PofloatRect(const Vector2D &p, const Rect &r);

};


#endif