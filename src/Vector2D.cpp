#include "Vector2D.h"


//fcts liés à Vector2D

Vector2D::Vector2D():x(0.f),y(0.f){}
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

float Vector2D :: getx() const{return x;}
float Vector2D :: gety() const{return y;}

void Vector2D :: setx(float xpos) {this->x = xpos;}
void Vector2D :: sety(float ypos) {this->y = ypos;}


Vector2D operator*(const Vector2D& vec, float n){

    return Vector2D(vec.getx() * n, vec.gety() * n);
}


//fonctions liés aux Rectangles
Rect::Rect():x(0),y(0),w(0),h(0){}
Rect::Rect(float x, float y , float w , float h):x(x),y(y),w(w),h(h){}

float Rect::getx() const{return this-> x;}
float Rect::gety() const{return this-> y;}
float Rect::getw() const{return this-> w;}
float Rect::geth() const{return this-> h;}

void Rect::setx(float x){this->x = x ;}
void Rect::sety(float y){this->x = y ;}
void Rect::setw(float w){this->x = w ;}
void Rect::seth(float h){this->x = h ;}
