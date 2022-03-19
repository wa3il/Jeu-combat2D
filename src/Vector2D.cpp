#include "Vector2D.h"

Vector2D::Vector2D():x(0),y(0){}
Vector2D::Vector2D(float xpos,float ypos):x(xpos),y(ypos){}
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

float& Vector2D :: getx() {return this->x;}
float& Vector2D :: gety() {return this->y;}

void Vector2D :: setx(float xpos) {this->x = xpos;}
void Vector2D :: sety(float ypos) {this->y = ypos;}
