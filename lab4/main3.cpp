#include <iostream>
#include "Polynomial3.h"

using namespace std;

int main() {
    cout << "=== ЕТАП 3: ФІНАЛЬНА ПРОГРАМА (З ОПЕРАТОРАМИ) ===" << endl;
    cout << "Многочленів у пам'яті: " << Polynomial::getObjectCount() << "\n\n";

    int size1, size2;
    
    while (true) {
        cout << "Введіть кількість коефіцієнтів для P1(x) (більше 0): ";
        if (cin >> size1 && size1 > 0) break;
        cout << "Помилка! Введіть додатнє ціле число.\n";
        cin.clear();
        cin.ignore(10000, '\n');
    }
    Polynomial p1(size1);
    cin >> p1; 

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
    
    cout << "\n=== ПЕРЕВАНТАЖЕНІ ОПЕРАТОРИ (+, -, *) ===" << endl;
    
    Polynomial sum = p1 + p2;
    cout << "P1 + P2 = " << sum << endl;

    Polynomial diff = p1 - p2;
    cout << "P1 - P2 = " << diff << endl;

    Polynomial prod = p1 * p2;
    cout << "P1 * P2 = " << prod << endl;

    cout << "\n=== НЕОПЕРАТОРНІ ФУНКЦІЇ ТЕЖ ПРАЦЮЮТЬ ===" << endl;
    cout << "Похідна P1'(x) = " << p1.derivative() << endl;

    cout << "\nЗараз об'єктів створено: " << Polynomial::getObjectCount() << endl;
    cout << "\n=== ЗАВЕРШЕННЯ ПРОГРАМИ ===" << endl;
    
    return 0; 
}