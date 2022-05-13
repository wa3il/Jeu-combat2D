#include "Vector2D.h"


//fcts liés à Vector2D

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


Vector2D operator*(const Vector2D& vec, int n){

    return Vector2D(vec.getx() * n, vec.gety() * n);
}


//fonctions liés aux Rectangles
Rect::Rect():x(0),y(0),w(0),h(0){}
Rect::Rect(int x, int y , int w , int h):x(x),y(y),w(w),h(h){}

int Rect::getx() const{return this-> x;}
int Rect::gety() const{return this-> y;}
int Rect::getw() const{return this-> w;}
int Rect::geth() const{return this-> h;}

void Rect::setx(int x){this->x = x ;}
void Rect::sety(int y){this->x = y ;}
void Rect::setw(int w){this->x = w ;}
void Rect::seth(int h){this->x = h ;}
