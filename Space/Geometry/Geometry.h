#pragma once

#ifndef _GEOMETRY_H_
#define _GEOMETRY_H_

#include <cmath>
const float Pi = acos(-1);

class Point2D;
class Vector2D;

class Point2D{
public:
    Point2D(): x(0), y(0){}
    Point2D(const float a,const float b): x(a), y(b){}

    Point2D(const Vector2D& a) = delete;
    float x = 0;
    float y = 0;

    virtual Point2D& operator+=(const Vector2D& a);
    virtual Point2D& operator-=(const Vector2D& a);
};

class Vector2D: public Point2D{
public:
    Vector2D(): Point2D(){}
    explicit Vector2D(const float a,const float b): Point2D(a, b){}
    explicit Vector2D(float a);
    Vector2D(const Point2D& a) = delete;
    void norm();

    float getAngle() const;
    float getLen() const;
    void rotate(const float& a);

    Vector2D operator-();

    Vector2D& operator-=(const Vector2D& a) override;
    Vector2D& operator+=(const Vector2D& a) override;
    Vector2D& operator*=(float c);
};


Vector2D operator-(const Point2D &a, const Point2D &b);
Point2D operator-(const Point2D& a, const Vector2D& b);
Point2D operator+(const Point2D& a, const Vector2D& b);
Point2D operator+(const Vector2D& a, const Point2D& b);
Vector2D operator+(const Vector2D& a, const Vector2D& b);
Vector2D operator-(const Vector2D& a, const Vector2D& b);
Vector2D operator*(const Vector2D& a, const float c);
Vector2D operator*(const float c, const Vector2D& a);

#endif