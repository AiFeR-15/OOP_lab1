#ifndef DERIVED_TRIANGLES_H
#define DERIVED_TRIANGLES_H

#include "TTriangle.h"

// ==========================================
// 1. ПОХІДНИЙ КЛАС: ПРЯМОКУТНИЙ ТРИКУТНИК (кут = 90)
// ==========================================
class RightTriangle : public TTriangle {
public:
    RightTriangle();
    RightTriangle(double legA, double legB);

    // Реалізація чисто віртуальних функцій пращура (override перевіряє точність)
    double area() const override;
    double perimeter() const override;
    void input() override;
    void output() const override;
    std::string getType() const override;
};

// ==========================================
// 2. ПОХІДНИЙ КЛАС: РІВНОБЕДРЕНИЙ ТРИКУТНИК (a == b)
// ==========================================
class IsoscelesTriangle : public TTriangle {
public:
    IsoscelesTriangle();
    IsoscelesTriangle(double side, double angleDeg);

    double area() const override;
    double perimeter() const override;
    void input() override;
    void output() const override;
    std::string getType() const override;
};

// ==========================================
// 3. ПОХІДНИЙ КЛАС: РІВНОСТОРОННІЙ ТРИКУТНИК (a == b, кут = 60)
// ==========================================
class EquilateralTriangle : public TTriangle {
public:
    EquilateralTriangle();
    EquilateralTriangle(double side);

    double area() const override;
    double perimeter() const override;
    void input() override;
    void output() const override;
    std::string getType() const override;
};

#endif