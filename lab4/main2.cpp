#include <iostream>
#include "Polynomial2.h"

using namespace std;

int main() {
    cout << "--- ЕТАП 2: СТАТИКА ТА ФУНКЦІЇ-ДРУЗІ ---" << endl;
    cout << "Многочленів у пам'яті: " << Polynomial::getObjectCount() << "\n\n";

    int size1, size2;
    
    // БЕЗПЕЧНЕ ВВЕДЕННЯ РОЗМІРУ P1
    while (true) {
        cout << "Введіть кількість коефіцієнтів для P1(x) (більше 0): ";
        if (cin >> size1 && size1 > 0) break;
        cout << "Помилка! Введіть додатнє ціле число.\n";
        cin.clear();
        cin.ignore(10000, '\n');
    }
    Polynomial p1(size1);
    cin >> p1; 

    // БЕЗПЕЧНЕ ВВЕДЕННЯ РОЗМІРУ P2
    while (true) {
        cout << "\nВведіть кількість коефіцієнтів для P2(x) (більше 0): ";
        if (cin >> size2 && size2 > 0) break;
        cout << "Помилка! Введіть додатнє ціле число.\n";
        cin.clear();
        cin.ignore(10000, '\n');
    }
    Polynomial p2(size2);
    cin >> p2;

    cout << "\nВаші многочлени:" << endl;
    cout << "P1(x) = " << p1 << endl; 
    cout << "P2(x) = " << p2 << endl;
    
    cout << "\nЗараз об'єктів створено: " << Polynomial::getObjectCount() << endl;

    cout << "\n--- ЕТАП 2: НЕОПЕРАТОРНІ ФУНКЦІЇ ---" << endl;
    
    cout << "Похідна P1'(x) = " << p1.derivative() << endl;

    // БЕЗПЕЧНЕ ВВЕДЕННЯ ЧИСЛА x
    double x;
    while (true) {
        cout << "Введіть число x: ";
        if (cin >> x) break;
        cout << "Помилка! Введіть число.\n";
        cin.clear();
        cin.ignore(10000, '\n');
    }
    cout << "Значення P1(x) при x=" << x << " дорівнює: " << p1.evaluate(x) << endl;

    // БЕЗПЕЧНЕ ВВЕДЕННЯ ЧИСЛА b
    double b;
    while (true) {
        cout << "Введіть число b: ";
        if (cin >> b) break;
        cout << "Помилка! Введіть число.\n";
        cin.clear();
        cin.ignore(10000, '\n');
    }
    cout << "(x - " << b << ") * P1(x) = " << p1.multiplyByXMinusB(b) << endl;
    cout << "P1(x + " << b << ") = " << p1.shiftX(b) << endl;

    cout << "Складена функція P1(P2(x)) = " << p1.compose(p2) << endl;

    cout << "\n--- ЗАВЕРШЕННЯ ПРОГРАМИ ---" << endl;
    return 0; 
}