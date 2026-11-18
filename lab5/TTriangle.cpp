#include "TTriangle.h"
#include <iostream>
#include <cmath>

using namespace std;

const double PI = acos(-1.0);

// Допоміжна функція для безпечного вводу додатних чисел
double readPositive(const char* prompt) {
    double val;
    while (true) {
        cout << prompt;
        if (cin >> val && val > 0) return val;
        cout << "Помилка! Введіть число більше нуля.\n";
        cin.clear();
        cin.ignore(10000, '\n');
    }
}

// ==========================================
// 1. РЕАЛІЗАЦІЯ БАЗОВОГО КЛАСУ TTriangle
// ==========================================
TTriangle::TTriangle() : a(1.0), b(1.0), angle(60.0) {}

// ОНОВЛЕНИЙ КОНСТРУКТОР: якщо передали від'ємні дані — змушує переввести
TTriangle::TTriangle(double sideA, double sideB, double angleDeg) {
    if (sideA > 0) {
        a = sideA;
    } else {
        cout << "[Конструктор] Передано некоректну сторону a (" << sideA << ").\n";
        a = readPositive("Введіть правильну додатну сторону a: ");
    }

    if (sideB > 0) {
        b = sideB;
    } else {
        cout << "[Конструктор] Передано некоректну сторону b (" << sideB << ").\n";
        b = readPositive("Введіть правильну додатну сторону b: ");
    }

    if (angleDeg > 0 && angleDeg < 180) {
        angle = angleDeg;
    } else {
        cout << "[Конструктор] Передано некоректний кут (" << angleDeg << ").\n";
        while (true) {
            cout << "Введіть правильний кут (від 1 до 179 град.): ";
            if (cin >> angle && angle > 0 && angle < 180) break;
            cout << "Помилка! Кут має бути в межах (0; 180).\n";
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }
}

// ==========================================
// 2. РЕАЛІЗАЦІЯ: RightTriangle (Прямокутний)
// ==========================================
RightTriangle::RightTriangle() : TTriangle(3.0, 4.0, 90.0) {}
RightTriangle::RightTriangle(double legA, double legB) : TTriangle(legA, legB, 90.0) {}

double RightTriangle::area() const {
    return 0.5 * a * b;
}

double RightTriangle::perimeter() const {
    return a + b + sqrt(a * a + b * b);
}

void RightTriangle::input() {
    cout << "--- Введення прямокутного трикутника ---\n";
    a = readPositive("Введіть перший катет (a): ");
    b = readPositive("Введіть другий катет (b): ");
    angle = 90.0;
}

void RightTriangle::output() const {
    cout << "Прямокутний трикутник (a = " << a << ", b = " << b << ", кут = " << angle << ")";
}

// ==========================================
// 3. РЕАЛІЗАЦІЯ: IsoscelesTriangle (Рівнобедрений)
// ==========================================
IsoscelesTriangle::IsoscelesTriangle() : TTriangle(5.0, 5.0, 40.0) {}
IsoscelesTriangle::IsoscelesTriangle(double side, double angleDeg) : TTriangle(side, side, angleDeg) {}

double IsoscelesTriangle::area() const {
    double rad = angle * PI / 180.0;
    return 0.5 * a * b * sin(rad);
}

double IsoscelesTriangle::perimeter() const {
    double rad = angle * PI / 180.0;
    double base = sqrt(a * a + b * b - 2 * a * b * cos(rad));
    return a + b + base;
}

void IsoscelesTriangle::input() {
    cout << "--- Введення рівнобедреного трикутника ---\n";
    a = readPositive("Введіть бічну сторону (a): ");
    b = a;
    while (true) {
        cout << "Введіть кут між бічними сторонами (від 1 до 179 град.): ";
        if (cin >> angle && angle > 0 && angle < 180) break;
        cout << "Помилка! Кут має бути в межах (0; 180).\n";
        cin.clear();
        cin.ignore(10000, '\n');
    }
}

void IsoscelesTriangle::output() const {
    cout << "Рівнобедрений трикутник (a = b = " << a << ", кут = " << angle << ")";
}

// ==========================================
// 4. РЕАЛІЗАЦІЯ: EquilateralTriangle (Рівносторонній)
// ==========================================
EquilateralTriangle::EquilateralTriangle() : TTriangle(4.0, 4.0, 60.0) {}
EquilateralTriangle::EquilateralTriangle(double side) : TTriangle(side, side, 60.0) {}

double EquilateralTriangle::area() const {
    return (sqrt(3.0) / 4.0) * a * a;
}

double EquilateralTriangle::perimeter() const {
    return 3.0 * a;
}

void EquilateralTriangle::input() {
    cout << "--- Введення рівностороннього трикутника ---\n";
    a = readPositive("Введіть сторону (a): ");
    b = a;
    angle = 60.0;
}

void EquilateralTriangle::output() const {
    cout << "Рівносторонній трикутник (a = b = c = " << a << ", кут = " << angle << ")";
}