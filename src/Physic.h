#ifndef PHYSIC_H
#define PHYSIC_H

#include "Vector2D.h"

class Physic
{
private:
    Vector2D m_position;
    Vector2D m_vitesse;
    Vector2D m_acceleration;
public:
    Physic();
    Physic(int posx,int posy);
    ~Physic();

    Vector2D getPos() const;
    Vector2D getVit() const;
    
    int getPosx() const;
    int getPosy() const;

    void setPos(int x, int y);
    void setPosx(int x);
    void setPosy(int y);
    void setVitx(int x);
    void setVity(int y);

    void ticks();

};


#endif