#include "Polynomial3.h"
#include <iostream>
#include <cmath>

using namespace std;

int Polynomial::objectCount = 0;

Polynomial::Polynomial() {
    n = 1;
    coef = new double[n];
    coef[0] = 0.0;
    objectCount++;
    cout << "[Конструктор за замовчуванням]" << endl;
}

Polynomial::Polynomial(int size) {
    if (size <= 0) size = 1;
    n = size;
    coef = new double[n];
    for (int i = 0; i < n; i++) coef[i] = 0.0;
    objectCount++;
    cout << "[Конструктор з параметром]" << endl;
}

Polynomial::Polynomial(int size, const double* arr) {
    if (size <= 0) size = 1;
    n = size;
    coef = new double[n];
    for (int i = 0; i < n; i++) {
        coef[i] = (arr != nullptr) ? arr[i] : 0.0;
    }
    objectCount++;
    cout << "[Конструктор з масиву]" << endl;
}

Polynomial::Polynomial(const Polynomial& other) {
    n = other.n;
    coef = new double[n];
    for (int i = 0; i < n; i++) coef[i] = other.coef[i];
    objectCount++;
    cout << "[Конструктор копіювання]" << endl;
}

Polynomial::~Polynomial() {
    delete[] coef;
    objectCount--;
    cout << "[Деструктор]" << endl;
}

Polynomial& Polynomial::operator=(const Polynomial& other) {
    cout << "[Оператор присвоєння]" << endl;
    if (this == &other) return *this;
    delete[] coef;
    n = other.n;
    coef = new double[n];
    for (int i = 0; i < n; i++) coef[i] = other.coef[i];
    return *this;
}

void Polynomial::input() {
    cout << "Введіть " << n << " коефіцієнтів (від a0 до a" << n - 1 << "):\n";
    for (int i = 0; i < n; i++) {
        while (true) {
            cout << "a[" << i << "] = ";
            if (cin >> coef[i]) {
                if (i == n - 1 && n > 1 && coef[i] == 0) {
                    cout << "Помилка! Старший коефіцієнт не може бути нулем.\n";
                    continue;
                }
                break;
            }
            cout << "Помилка вводу! Введіть число.\n";
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }
}

void Polynomial::output() const {
    cout << *this << endl;
}

int Polynomial::getObjectCount() {
    return objectCount;
}

istream& operator>>(istream& is, Polynomial& p) {
    p.input();
    return is;
}

ostream& operator<<(ostream& os, const Polynomial& p) {
    bool allZero = true;
    for (int i = 0; i < p.n; i++) {
        if (p.coef[i] != 0) {
            if (!allZero && p.coef[i] > 0) os << " + ";
            os << p.coef[i];
            if (i > 0) os << "*x^" << i;
            allZero = false;
        }
    }
    if (allZero) os << "0";
    return os;
}

Polynomial Polynomial::copyPolynomial() const {
    return Polynomial(*this);
}

double Polynomial::evaluate(double x) const {
    double result = 0.0;
    for (int i = 0; i < n; i++) {
        result += coef[i] * pow(x, i);
    }
    return result;
}

Polynomial Polynomial::derivative() const {
    if (n <= 1) return Polynomial(1);
    Polynomial deriv(n - 1);
    for (int i = 1; i < n; i++) {
        deriv.coef[i - 1] = coef[i] * i;
    }
    return deriv;
}

Polynomial Polynomial::multiplyByXMinusB(double b) const {
    Polynomial res(n + 1);
    for (int i = 0; i < n; i++) res.coef[i + 1] = coef[i];
    for (int i = 0; i < n; i++) res.coef[i] -= b * coef[i];
    return res;
}

Polynomial Polynomial::compose(const Polynomial& q) const {
    Polynomial res(1);
    for (int i = n - 1; i >= 0; i--) {
        res = (res * q);
        res.coef[0] += coef[i];
    }
    return res;
}

Polynomial Polynomial::shiftX(double b) const {
    Polynomial xb(2);
    xb.coef[0] = b;
    xb.coef[1] = 1.0;
    return this->compose(xb);
}

void Polynomial::divide(const Polynomial& divisor, Polynomial& quotient, Polynomial& remainder) const {
    if (divisor.n == 1 && divisor.coef[0] == 0) {
        cout << "Помилка! Ділення на нуль неможливе.\n";
        return;
    }

    int degA = n - 1;
    int degB = divisor.n - 1;

    if (degA < degB) {
        quotient = Polynomial(1);
        remainder = this->copyPolynomial();
        return;
    }

    quotient = Polynomial(degA - degB + 1);
    remainder = this->copyPolynomial();

    for (int i = degA - degB; i >= 0; i--) {
        double coeff = remainder.coef[i + degB] / divisor.coef[degB];
        quotient.coef[i] = coeff;
        for (int j = 0; j <= degB; j++) {
            remainder.coef[i + j] -= coeff * divisor.coef[j];
        }
    }
}

Polynomial Polynomial::operator+(const Polynomial& other) const {
    int maxN = (n > other.n) ? n : other.n;
    Polynomial res(maxN);
    for (int i = 0; i < n; i++) res.coef[i] += coef[i];
    for (int i = 0; i < other.n; i++) res.coef[i] += other.coef[i];
    return res;
}

Polynomial Polynomial::operator-(const Polynomial& other) const {
    int maxN = (n > other.n) ? n : other.n;
    Polynomial res(maxN);
    for (int i = 0; i < n; i++) res.coef[i] += coef[i];
    for (int i = 0; i < other.n; i++) res.coef[i] -= other.coef[i];
    return res;
}

Polynomial Polynomial::operator*(const Polynomial& other) const {
    Polynomial res(n + other.n - 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < other.n; j++) {
            res.coef[i + j] += coef[i] * other.coef[j];
        }
    }
    return res;
}