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
        int getx()const;
        int gety()const;

        void setx(int xpos);
        void sety(int ypos);

};

Vector2D operator*(const Vector2D& vec, int f);


class Rect{
    private:

    int x,y,w,h;


    public:

    Rect();
    Rect(int x, int y , int w , int h);

    int getx() const;
    int gety() const;
    int getw() const;
    int geth() const;

    void setx(int x);
    void sety(int y);
    void setw(int w);
    void seth(int h);
};

#endif