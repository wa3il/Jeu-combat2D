#ifndef VECTOR2D_H
#define VECTOR2D_H

#include <iostream>

class Vector2D{
    private:
        float x,y;

    public:
        /**constructeur destructeur */
        Vector2D();
        Vector2D(float xpos,float ypos);
        ~Vector2D();

        /**Surcharge d'operateur de la classe vecteur*/
        Vector2D operator+(const Vector2D& op)const;
        Vector2D& operator =(const Vector2D& op);
        Vector2D& operator+=(const Vector2D& op);

        /** Mutateur est accesseur */
        float& getx();
        float& gety();

        void setx(float xpos);
        void sety(float ypos);

};

#endif