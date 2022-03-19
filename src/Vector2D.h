#ifndef VECTOR2D_H
#define VECTOR2D_H

#include <iostream>

class Vector2D{
    private:
        float x,y;

    public:
        /**Surcharge d'operateur de la classe vecteur*/
        Vector2D operator+(const Vector2D& op)const;
        Vector2D& operator =(const Vector2D& op);
        Vector2D& operator+=(const Vector2D& op);

        /** Mutateur est accesseur */
        float Vector2D :: getx();
        float Vector2D :: gety();

};

#endif