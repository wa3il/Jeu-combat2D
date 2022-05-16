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
        float getx()const;
        float gety()const;

        void setx(float xpos);
        void sety(float ypos);

};

Vector2D operator*(const Vector2D& vec, float f);


class Rect{
    private:

    float x,y,w,h;


    public:

    Rect();
    Rect(float x, float y , float w , float h);

    float getx() const;
    float gety() const;
    float getw() const;
    float geth() const;

    void setx(float x);
    void sety(float y);
    void setw(float w);
    void seth(float h);
};

#endif