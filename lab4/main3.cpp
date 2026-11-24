#include <iostream>
#include "Polynomial3.h"

using namespace std;

int getValidSize(const char* prompt) {
    int val;
    while (true) {
        cout << prompt;
        if (cin >> val && val > 0) return val;
        cout << "Помилка! Введіть додатне ціле число.\n";
        cin.clear();
        cin.ignore(10000, '\n');
    }
}

double getValidDouble(const char* prompt) {
    double val;
    while (true) {
        cout << prompt;
        if (cin >> val) return val;
        cout << "Помилка! Введіть число.\n";
        cin.clear();
        cin.ignore(10000, '\n');
    }
}

int main() {
    cout << "Кількість об'єктів: " << Polynomial::getObjectCount() << "\n\n";

    int size1 = getValidSize("Введіть кількість коефіцієнтів для P1(x): ");
    Polynomial p1(size1);
    p1.input();

    cout << "P1(x) = ";
    p1.output();

    double initArr[] = {2.0, -1.0, 3.0};
    Polynomial pArr(3, initArr);
    cout << "P_arr(x) = ";
    pArr.output();

    Polynomial pCopy = p1;
    cout << "Копія P1(x) = ";
    pCopy.output();

    Polynomial pEmpty;
    pEmpty = p1;
    cout << "P_empty(x) після присвоєння = ";
    pEmpty.output();

    int size2 = getValidSize("\nВведіть кількість коефіцієнтів для P2(x): ");
    Polynomial p2(size2);
    cin >> p2;

    cout << "\nP1(x) = " << p1 << "\n";
    cout << "P2(x) = " << p2 << "\n";
    cout << "Кількість об'єктів: " << Polynomial::getObjectCount() << "\n\n";

    Polynomial sum = p1 + p2;
    Polynomial diff = p1 - p2;
    Polynomial prod = p1 * p2;

    cout << "P1 + P2 = " << sum << "\n";
    cout << "P1 - P2 = " << diff << "\n";
    cout << "P1 * P2 = " << prod << "\n\n";

    Polynomial manualCopy = p1.copyPolynomial();
    cout << "copyPolynomial(P1) = " << manualCopy << "\n";

    Polynomial deriv = p1.derivative();
    cout << "P1'(x) = " << deriv << "\n";

    double x = getValidDouble("Введіть x для обчислення P1(x): ");
    cout << "P1(" << x << ") = " << p1.evaluate(x) << "\n";

    double b = getValidDouble("Введіть число b: ");
    Polynomial multXB = p1.multiplyByXMinusB(b);
    Polynomial shifted = p1.shiftX(b);
    cout << "(x - " << b << ") * P1(x) = " << multXB << "\n";
    cout << "P1(x + " << b << ") = " << shifted << "\n";

    Polynomial composed = p1.compose(p2);
    cout << "P1(P2(x)) = " << composed << "\n\n";

    Polynomial quotient, remainder;
    p1.divide(p2, quotient, remainder);
    cout << "Частка від ділення P1 на P2: " << quotient << "\n";
    cout << "Залишок від ділення: " << remainder << "\n\n";

    cout << "Кількість об'єктів перед виходом: " << Polynomial::getObjectCount() << "\n";
    return 0;
}