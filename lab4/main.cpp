#include <iostream>
#include <limits>
#include <windows.h>
#include "Polynomial.h"

using namespace std;

// Функція, яка постійно просить ввести розмір, поки він не буде > 0
int getValidInt(const char* prompt) {
    int val;
    while (true) {
        cout << prompt;
        if (cin >> val && val > 0) {
            return val;
        }
        cout << "Помилка! Розмір має бути цілим числом і більше нуля. Спробуйте знову.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

// Функція для безпечного вводу дробів (наприклад, для x або b)
double getValidDouble(const char* prompt) {
    double val;
    while (true) {
        cout << prompt;
        if (cin >> val) {
            return val;
        }
        cout << "Помилка! Введіть коректне число.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    cout << "=== СТВОРЕННЯ МНОГОЧЛЕНІВ ===\n";
    // Тут програма не пропустить далі, якщо ввести < 0
    int size1 = getValidInt("Введіть кількість коефіцієнтів для P1(x): ");
    Polynomial p1(size1);
    cin >> p1;

    int size2 = getValidInt("\nВведіть кількість коефіцієнтів для P2(x): ");
    Polynomial p2(size2);
    cin >> p2;

    cout << "\nP1(x) = " << p1 << "\n";
    cout << "P2(x) = " << p2 << "\n\n";

    cout << "=== МАТЕМАТИЧНІ ОПЕРАЦІЇ ===\n";
    Polynomial sum = p1 + p2;
    cout << "P1 + P2 = " << sum << "\n";
    
    Polynomial prod = p1 * p2;
    cout << "P1 * P2 = " << prod << "\n\n";

    cout << "=== СПЕЦІАЛЬНІ ФУНКЦІЇ ===\n";
    double x = getValidDouble("Введіть число x для обчислення значення: ");
    cout << "P1(" << x << ") = " << p1.evaluate(x) << "\n\n";

    Polynomial deriv = p1.derivative();
    cout << "Похідна P1'(x) = " << deriv << "\n\n";

    double b = getValidDouble("Введіть число b: ");
    
    Polynomial p_xb = p1.multiplyByXMinusB(b);
    cout << "(x - " << b << ") * P1(x) = " << p_xb << "\n";

    Polynomial p_shift = p1.shiftX(b);
    cout << "P1(x + " << b << ") = " << p_shift << "\n";

    Polynomial p_comp = p1.compose(p2);
    cout << "P1(P2(x)) = " << p_comp << "\n\n";

    cout << "Многочленів у пам'яті: " << Polynomial::getObjectCount() << "\n";
    cout << "=== ЗАВЕРШЕННЯ ПРОГРАМИ ===\n";
    
    return 0; 
}