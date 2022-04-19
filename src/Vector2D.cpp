#include "Vector2D.h"

Vector2D::Vector2D():x(0),y(0){}
Vector2D::Vector2D(int xpos,int ypos):x(xpos),y(ypos){}
Vector2D::~Vector2D(){}

Vector2D Vector2D :: operator+(const Vector2D& op)const{
            Vector2D resultat;
            resultat.x = x + op.x;
            resultat.y = y + op.y;
            return resultat;
        }

Vector2D& Vector2D :: operator =(const Vector2D& op){
            x = op.x;
            y = op.y;
            return *this;
        }

Vector2D& Vector2D ::operator+=(const Vector2D& op){
            x = x + op.x;
            y = y + op.y;
            return *this;
        }

int Vector2D :: getx() const{return x;}
int Vector2D :: gety() const{return y;}

void Vector2D :: setx(int xpos) {this->x = xpos;}
void Vector2D :: sety(int ypos) {this->y = ypos;}
