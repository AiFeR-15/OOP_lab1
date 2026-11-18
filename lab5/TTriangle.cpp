#include "TTriangle.h"
#include <iostream>

using namespace std;

// Допоміжна функція для безпечного вводу додатних чисел (static — локальна для цього файлу)
static double readPositive(const char* prompt) {
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
// РЕАЛІЗАЦІЯ БАЗОВОГО КЛАСУ TTriangle
// ==========================================
TTriangle::TTriangle() : a(1.0), b(1.0), angle(60.0) {}

// КОНСТРУКТОР З ПАРАМЕТРАМИ: якщо передали від'ємні дані — змушує переввести
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