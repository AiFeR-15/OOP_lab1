#include "DerivedTriangles.h"
#include <iostream>
#include <cmath>

using namespace std;

// Константа Пі для переведення градусів у радіани
const double PI = acos(-1.0);

// Допоміжна внутрішня функція для безпечного вводу чисел
double readPositiveDouble(const string& prompt) {
    double val;
    while (true) {
        cout << prompt;
        if (cin >> val && val > 0) return val;
        cout << "Помилка! Введіть додатне число.\n";
        cin.clear();
        cin.ignore(10000, '\n');
    }
}

// ==========================================
// 1. РЕАЛІЗАЦІЯ: RightTriangle (Прямокутний)
// ==========================================
RightTriangle::RightTriangle() : TTriangle(3.0, 4.0, 90.0) {}

RightTriangle::RightTriangle(double legA, double legB) : TTriangle(legA, legB, 90.0) {}

double RightTriangle::area() const {
    return 0.5 * a * b;
}

double RightTriangle::perimeter() const {
    double c = sqrt(a * a + b * b); // Гіпотенуза за теоремою Піфагора
    return a + b + c;
}

void RightTriangle::input() {
    cout << "--- Введення даних для прямокутного трикутника ---\n";
    a = readPositiveDouble("Введіть перший катет (a): ");
    b = readPositiveDouble("Введіть другий катет (b): ");
    angle = 90.0; // Фіксований кут 90 градусів
}

void RightTriangle::output() const {
    cout << "[Прямокутний трикутник] Катети: a = " << a << ", b = " << b 
         << ", кут = " << angle << " град.";
}

string RightTriangle::getType() const {
    return "Прямокутний трикутник";
}

// ==========================================
// 2. РЕАЛІЗАЦІЯ: IsoscelesTriangle (Рівнобедрений)
// ==========================================
IsoscelesTriangle::IsoscelesTriangle() : TTriangle(5.0, 5.0, 40.0) {}

IsoscelesTriangle::IsoscelesTriangle(double side, double angleDeg)
    : TTriangle(side, side, angleDeg) {}

double IsoscelesTriangle::area() const {
    double rad = angle * PI / 180.0;
    return 0.5 * a * b * sin(rad); // Оскільки b == a, це 0.5 * a^2 * sin(alpha)
}

double IsoscelesTriangle::perimeter() const {
    double rad = angle * PI / 180.0;
    // Основа за теоремою косинусів: c = sqrt(a^2 + b^2 - 2ab*cos(alpha))
    double base = sqrt(a * a + b * b - 2 * a * b * cos(rad));
    return a + b + base;
}

void IsoscelesTriangle::input() {
    cout << "--- Введення даних для рівнобедреного трикутника ---\n";
    a = readPositiveDouble("Введіть довжину бічної сторони (a): ");
    b = a; // Бічні сторони рівні
    while (true) {
        cout << "Введіть кут між бічними сторонами (від 1 до 179 град.): ";
        if (cin >> angle && angle > 0 && angle < 180) break;
        cout << "Помилка! Кут має бути в межах (0; 180).\n";
        cin.clear();
        cin.ignore(10000, '\n');
    }
}

void IsoscelesTriangle::output() const {
    cout << "[Рівнобедрений трикутник] Бічні сторони: a = b = " << a 
         << ", кут між ними = " << angle << " град.";
}

string IsoscelesTriangle::getType() const {
    return "Рівнобедрений трикутник";
}

// ==========================================
// 3. РЕАЛІЗАЦІЯ: EquilateralTriangle (Рівносторонній)
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
    cout << "--- Введення даних для рівностороннього трикутника ---\n";
    a = readPositiveDouble("Введіть сторону трикутника (a): ");
    b = a;
    angle = 60.0; // Усі кути рівностороннього трикутника по 60 градусів
}

void EquilateralTriangle::output() const {
    cout << "[Рівносторонній трикутник] Усі сторони: a = b = c = " << a 
         << ", кут = " << angle << " град.";
}

string EquilateralTriangle::getType() const {
    return "Рівносторонній трикутник";
}