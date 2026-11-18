#include <iostream>
#include <vector>
#include "TTriangle.h"
#include "DerivedTriangles.h"

using namespace std;

// ==========================================
// ПОЛІМОРФНА ФУНКЦІЯ (Виведення інформації)
// ==========================================
void showTrianglesInfo(const vector<TTriangle*>& triangles) {
    cout << "\n======================================================\n";
    cout << "           ІНФОРМАЦІЯ ПРО ВСІ ТРИКУТНИКИ\n";
    cout << "======================================================\n";

    cout << "--- Трикутники, створені через конструктори ---\n";
    for (size_t i = 0; i < triangles.size(); i++) {
        // Перед 4-м елементом (індекс 3) ставимо заголовок для користувацького трикутника
        if (i == 3) {
            cout << "--- Трикутник, введений користувачем ---\n";
        }

        cout << i + 1 << ". ";
        triangles[i]->output();
        cout << "\n   Площа = " << triangles[i]->area() << " (кв. см)"
             << ", Периметр = " << triangles[i]->perimeter() << " (см)\n\n";
    }
}

int main() {
    vector<TTriangle*> triangles;

    // 1. Створюємо 3 об'єкти через конструктори з параметрами (МІНЯТИ РОЗМІРИ ТУТ)
    triangles.push_back(new RightTriangle(3.0, 4.0));
    triangles.push_back(new IsoscelesTriangle(6.0, 30.0));
    triangles.push_back(new EquilateralTriangle(5.0));

    // 2. Меню вибору трикутника для ручного введення (4-й об'єкт)
    int choice;
    while (true) {
        cout << "Оберіть тип трикутника, який хочете ввести вручну:\n";
        cout << "1 - Прямокутний трикутник\n";
        cout << "2 - Рівнобедрений трикутник\n";
        cout << "3 - Рівносторонній трикутник\n";
        cout << "Ваш вибір: ";

        if (cin >> choice && choice >= 1 && choice <= 3) {
            break;
        }
        cout << "Помилка! Введіть цифру 1, 2 або 3.\n\n";
        cin.clear();
        cin.ignore(10000, '\n');
    }

    TTriangle* customTriangle = nullptr;
    if (choice == 1) {
        customTriangle = new RightTriangle();
    } else if (choice == 2) {
        customTriangle = new IsoscelesTriangle();
    } else {
        customTriangle = new EquilateralTriangle();
    }

    // Поліморфний виклик input(): запуститься введення саме для обраного типу
    customTriangle->input();
    triangles.push_back(customTriangle);

    // 3. Викликаємо поліморфну функцію для виведення всіх 4 трикутників
    showTrianglesInfo(triangles);

    // 4. Очищуємо динамічну пам'ять (спрацьовує віртуальний деструктор)
    for (size_t i = 0; i < triangles.size(); i++) {
        delete triangles[i];
    }

    return 0;
}