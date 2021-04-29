
#include "Geometry.h"

Vector2D operator-(const Point2D &a, const Point2D &b){
    return Vector2D(a.x - b.x, a.y - b.y);
}


Point2D operator-(const Point2D& a, const Vector2D& b){
    Point2D c(a);
    c-= b;
    return c;
}

Point2D operator+(const Point2D& a, const Vector2D& b){
    Point2D c(a);
    c += b;
    return c;
}

Point2D operator+(const Vector2D& a, const Point2D& b){
    return b + a;
}


Vector2D operator+(const Vector2D& a, const Vector2D& b){
    Vector2D c(a);
    c += b;
    return c;
}
Vector2D operator-(const Vector2D& a, const Vector2D& b){
    Vector2D c(a);
    c -= b;
    return c;
}

Vector2D operator*(const Vector2D& a, const float c){
    Vector2D b(a);
    b *= c;
    return b;
}

Vector2D operator*(const float c, const Vector2D& a){
    return a * c;
}

Point2D& Point2D::operator+=(const Vector2D& a){
    x += a.x;
    y += a.y;
    return *this;
}
Point2D& Point2D::operator-=(const Vector2D& a){
    x -= a.x;
    y -= a.y;
    return *this;
}

Vector2D::Vector2D(const float a){
    x = cos(a);
    y = sin(a);
}

void Vector2D::norm(){
    float len = sqrt(x * x + y * y);
    if(len == 0) return;
    x /= len;
    y /= len;
    return;
}

float Vector2D::getAngle() const {
    float a = atan2(y, x);
    return a;
}

float Vector2D::getLen() const {
    float l = sqrt(x * x + y * y);
    return l;
}

Vector2D Vector2D::operator-(){
    Vector2D a(*this);
    a.x = -a.x;
    a.y = -a.y;
    return a;
}

Vector2D& Vector2D::operator-=(const Vector2D& a){
    x -= a.x;
    y -= a.y;
    return *this;
}
Vector2D& Vector2D::operator+=(const Vector2D& a){
    x += a.x;
    y += a.y;
    return *this;
}
Vector2D& Vector2D::operator*=(const float c){
    x *= c;
    y *= c;
    return *this;
}

void Vector2D::rotate(const float& a) {
    *this = Vector2D(getAngle() + a);
}