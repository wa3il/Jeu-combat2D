#ifndef VECTOR2D_H
#define VECTOR2D_H

#include <iostream>

class Vector2D{
    private:
        int x,y;

    public:
        /**constructeur destructeur */
        Vector2D();
        Vector2D(int xpos,int ypos);
        ~Vector2D();

        /**Surcharge d'operateur de la classe vecteur*/
        Vector2D operator+(const Vector2D& op)const;
        Vector2D& operator =(const Vector2D& op);
        Vector2D& operator+=(const Vector2D& op);

        /** Mutateur est accesseur */
        int& getx();
        int& gety();

        void setx(int xpos);
        void sety(int ypos);

};

#endif