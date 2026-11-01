#include "Polynomial.h"
#include <cmath>
#include <limits> 

using namespace std;

int Polynomial::objectCount = 0;

Polynomial::Polynomial() {
    n = 1;
    coef = new double[n];
    coef[0] = 0.0;
    objectCount++;
    cout << "[Конструктор за замовчуванням] Створено об'єкт.\n";
}

Polynomial::Polynomial(int size) {
    if (size <= 0) size = 1; // Захисний механізм базового рівня
    n = size;
    coef = new double[n];
    for (int i = 0; i < n; i++) coef[i] = 0.0;
    objectCount++;
    cout << "[Конструктор з параметрами] Створено масив на " << n << " ел.\n";
}

Polynomial::Polynomial(const Polynomial& other) {
    n = other.n;
    coef = new double[n];
    for (int i = 0; i < n; i++) coef[i] = other.coef[i];
    objectCount++;
    cout << "[Конструктор копіювання] Створено точну копію.\n";
}

Polynomial::~Polynomial() {
    delete[] coef;
    objectCount--;
    cout << "[Деструктор] Пам'ять звільнено.\n";
}

Polynomial& Polynomial::operator=(const Polynomial& other) {
    cout << "[Оператор присвоєння] Працює копіювання.\n";
    if (this == &other) return *this; 
    delete[] coef;
    n = other.n;
    coef = new double[n];
    for (int i = 0; i < n; i++) coef[i] = other.coef[i];
    return *this;
}

Polynomial Polynomial::copyPolynomial() const {
    return Polynomial(*this); 
}

double Polynomial::evaluate(double x) const {
    double result = 0.0;
    for (int i = 0; i < n; i++) result += coef[i] * pow(x, i);
    return result;
}

Polynomial Polynomial::derivative() const {
    if (n <= 1) return Polynomial(1); 
    Polynomial deriv(n - 1);
    for (int i = 1; i < n; i++) deriv.coef[i - 1] = coef[i] * i;
    return deriv;
}

int Polynomial::getObjectCount() {
    return objectCount;
}

Polynomial Polynomial::multiplyByXMinusB(double b) const {
    Polynomial res(n + 1);
    for (int i = 0; i < n; i++) res.coef[i + 1] = coef[i]; 
    for (int i = 0; i < n; i++) res.coef[i] -= b * coef[i]; 
    return res;
}

Polynomial Polynomial::shiftX(double b) const {
    Polynomial res(n);
    Polynomial xb(2); 
    xb.coef[0] = b; xb.coef[1] = 1.0;
    
    for (int i = n - 1; i >= 0; i--) {
        Polynomial temp(1);
        temp.coef[0] = coef[i];
        res = (res * xb) + temp;
    }
    return res;
}

Polynomial Polynomial::compose(const Polynomial& q) const {
    Polynomial res(1);
    for (int i = n - 1; i >= 0; i--) {
        Polynomial temp(1);
        temp.coef[0] = coef[i];
        res = (res * q) + temp;
    }
    return res;
}

istream& operator>>(istream& is, Polynomial& p) {
    cout << "Введіть " << p.n << " коефіцієнтів (від a0 до a" << p.n-1 << "):\n";
    for (int i = 0; i < p.n; i++) {
        while (true) {
            cout << "a[" << i << "] = ";
            if (is >> p.coef[i]) break; 
            cout << "Помилка! Введіть число.\n";
            is.clear();
            is.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
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

Polynomial Polynomial::operator+(const Polynomial& other) const {
    int max_n = (n > other.n) ? n : other.n;
    Polynomial res(max_n);
    for (int i = 0; i < max_n; i++) {
        double v1 = (i < n) ? coef[i] : 0.0;
        double v2 = (i < other.n) ? other.coef[i] : 0.0;
        res.coef[i] = v1 + v2;
    }
    return res;
}

Polynomial Polynomial::operator-(const Polynomial& other) const {
    int max_n = (n > other.n) ? n : other.n;
    Polynomial res(max_n);
    for (int i = 0; i < max_n; i++) {
        double v1 = (i < n) ? coef[i] : 0.0;
        double v2 = (i < other.n) ? other.coef[i] : 0.0;
        res.coef[i] = v1 - v2;
    }
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