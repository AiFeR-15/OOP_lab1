#include "Polynomial.h"
#include <iostream>

using namespace std;

// ==========================================
// БЛОК 1: КОНСТРУКТОРИ
// ==========================================

Polynomial::Polynomial() {
    n = 1;
    coef = new double[n];
    coef[0] = 0.0;
    cout << "[Конструктор за замовчуванням] Створено многочлен нульового степеня." << endl;
}

Polynomial::Polynomial(int size) {
    if (size <= 0) size = 1; 
    n = size;
    coef = new double[n];
    for (int i = 0; i < n; i++) {
        coef[i] = 0.0;
    }
    cout << "[Конструктор з параметрами] Виділено пам'ять на " << n << " елементів." << endl;
}

Polynomial::Polynomial(const Polynomial& other) {
    n = other.n;
    coef = new double[n];
    for (int i = 0; i < n; i++) {
        coef[i] = other.coef[i];
    }
    cout << "[Конструктор копіювання] Створено точну копію масиву." << endl;
}

// ==========================================
// БЛОК 2: ДЕСТРУКТОР
// ==========================================
Polynomial::~Polynomial() {
    delete[] coef; 
    cout << "[Деструктор] Пам'ять звільнено." << endl;
}

// ==========================================
// БЛОК 3: ОПЕРАТОР ПРИСВОЄННЯ
// ==========================================
Polynomial& Polynomial::operator=(const Polynomial& other) {
    cout << "[Оператор присвоєння] Працює копіювання об'єкта." << endl;
    
    if (this == &other) return *this; 
    
    delete[] coef; 
    n = other.n;
    coef = new double[n]; 
    
    for (int i = 0; i < n; i++) {
        coef[i] = other.coef[i];
    }
    return *this;
}

// ==========================================
// БЛОК 4: ФУНКЦІЇ ВВЕДЕННЯ ТА ВИВЕДЕННЯ
// ==========================================

void Polynomial::input() {
    cout << "Введіть " << n << " коефіцієнтів (від a0 до a" << n-1 << "):" << endl;
    for (int i = 0; i < n; i++) {
        while (true) {
            cout << "a[" << i << "] = ";
            if (cin >> coef[i]) break;
            
            cout << "Помилка вводу. Будь ласка, введіть число." << endl;
            cin.clear();
            cin.ignore(10000, '\n'); // Замінили limits на просте число 10000
        }
    }
}

void Polynomial::output() const {
    bool allZero = true;
    for (int i = 0; i < n; i++) {
        if (coef[i] != 0) {
            if (!allZero && coef[i] > 0) cout << " + ";
            cout << coef[i];
            if (i > 0) cout << "*x^" << i;
            allZero = false;
        }
    }
    if (allZero) cout << "0";
    cout << endl;
}