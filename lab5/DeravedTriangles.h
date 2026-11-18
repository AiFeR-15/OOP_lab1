#ifndef DERIVED_TRIANGLES_H
#define DERIVED_TRIANGLES_H

#include "TTriangle.h"

// ==========================================
// ПОХІДНИЙ КЛАС 1: Прямокутний трикутник (кут = 90)
// ==========================================
class RightTriangle : public TTriangle {
public:
    RightTriangle();
    RightTriangle(double legA, double legB);

    double area() const override;
    double perimeter() const override;
    void input() override;
    void output() const override;
};

// ==========================================
// ПОХІДНИЙ КЛАС 2: Рівнобедрений трикутник (a == b)
// ==========================================
class IsoscelesTriangle : public TTriangle {
public:
    IsoscelesTriangle();
    IsoscelesTriangle(double side, double angleDeg);

    double area() const override;
    double perimeter() const override;
    void input() override;
    void output() const override;
};

// ==========================================
// ПОХІДНИЙ КЛАС 3: Рівносторонній трикутник (a == b, кут = 60)
// ==========================================
class EquilateralTriangle : public TTriangle {
public:
    EquilateralTriangle();
    EquilateralTriangle(double side);

    double area() const override;
    double perimeter() const override;
    void input() override;
    void output() const override;
};

#endif