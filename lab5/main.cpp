#include <iostream>
#include <vector>
#include "TTriangle.h"

using namespace std;

// ==========================================
// ПОЛІМОРФНА ФУНКЦІЯ (Вимога завдання)
// Приймає список вказівників на базовий клас і виводить дані кожного об'єкта
// ==========================================
void showTrianglesInfo(const vector<TTriangle*>& triangles) {
    cout << "\n=== ІНФОРМАЦІЯ ПРО ВСІ ТРИКУТНИКИ ===\n";
    for (size_t i = 0; i < triangles.size(); i++) {
        cout << i + 1 << ". ";
        triangles[i]->output();
        cout << "\n   Площа = " << triangles[i]->area()
             << ", Периметр = " << triangles[i]->perimeter() << "\n\n";
    }
}

int main() {
    vector<TTriangle*> triangles;

    // 1. Створюємо об'єкти через конструктори (без ручного вводу)
    triangles.push_back(new RightTriangle(3.0, 4.0));
    triangles.push_back(new IsoscelesTriangle(6.0, 30.0));
    triangles.push_back(new EquilateralTriangle(5.0));

    // 2. Створюємо об'єкт і заповнюємо його з клавіатури через input()
    TTriangle* customTriangle = new RightTriangle();
    customTriangle->input();
    triangles.push_back(customTriangle);

    // 3. Викликаємо поліморфну функцію для всіх різнотипових трикутників
    showTrianglesInfo(triangles);

    // 4. Очищуємо пам'ять (спрацьовує віртуальний деструктор)
    for (size_t i = 0; i < triangles.size(); i++) {
        delete triangles[i];
    }

    return 0;
}