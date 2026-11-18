#ifndef TTRIANGLE_H
#define TTRIANGLE_H

#include <iostream>

// ==========================================
// БАЗОВИЙ АБСТРАКТНИЙ КЛАС (Корінь ієрархії)
// ==========================================
class TTriangle {
protected:
    // Члени-дані базового класу (доступні нащадкам)
    double a;      // Перша сторона
    double b;      // Друга сторона
    double angle;  // Кут між сторонами (у градусах)

public:
    // Конструктори та віртуальний деструктор
    TTriangle();
    TTriangle(double sideA, double sideB, double angleDeg);
    virtual ~TTriangle() {}

    // Чисто віртуальні функції (= 0 робить клас абстрактним)
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual void input() = 0;
    virtual void output() const = 0;
};

#endif