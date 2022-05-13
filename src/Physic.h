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

    Vector2D getPos() const;
    int getPosx() const;
    int getPosy() const;

    void setPos(int x, int y);
    void setPosx(int x);
    void setPosy(int y);

    Vector2D getVit() const;
    void setVit(int x, int y);
    void setVitx(int x);
    void setVity(int y);

    void ticks(float deltaTime);

    bool PointRect(const Vector2D &p, const Rect &r);

};


#endif