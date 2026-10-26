#include <iostream>
#include <cstdio>
using namespace std;

// Структура містить ЛИШЕ дані (без функцій всередині)
struct TFazzyNumber {
    double left_e;
    double x;
    double right_e;
};

void init(TFazzyNumber& obj, double le, double val, double re) {
    obj.left_e = le;
    obj.x = val;
    obj.right_e = re;
}

void input(TFazzyNumber& obj) {
    cout << "Введіть x (саме число): ";
    cin >> obj.x;
    cout << "Введіть e1 (ліву похибку): ";
    cin >> obj.left_e;
    cout << "Введіть e2 (праву похибку): ";
    cin >> obj.right_e;
}

void output(TFazzyNumber obj) {
    cout << "(" << obj.x - obj.left_e << ", "
         << obj.x << ", "
         << obj.x + obj.right_e << ")\n";
}

char* toPChar(TFazzyNumber obj) {
    char* buffer = new char[100];
    sprintf(buffer, "(%.2f, %.2f, %.2f)", 
            obj.x - obj.left_e, obj.x, obj.x + obj.right_e);
    return buffer;
}


TFazzyNumber operator+(TFazzyNumber A, TFazzyNumber B) {
    TFazzyNumber result;
    result.x = A.x + B.x;
    result.left_e = A.left_e + B.left_e;
    result.right_e = A.right_e + B.right_e;
    return result;
}

TFazzyNumber operator-(TFazzyNumber A, TFazzyNumber B) {
    TFazzyNumber result;
    result.x = A.x - B.x;
    result.left_e = A.left_e + B.left_e; 
    result.right_e = A.right_e + B.right_e;
    return result;
}

TFazzyNumber operator*(TFazzyNumber A, TFazzyNumber B) {
    TFazzyNumber result;
    result.x = A.x * B.x;
    result.left_e = B.x * A.left_e + A.x * B.left_e - A.left_e * B.left_e;
    result.right_e = B.x * A.right_e + A.x * B.right_e + A.right_e * B.right_e;
    return result;
}

TFazzyNumber operator/(TFazzyNumber A, TFazzyNumber B) {
    TFazzyNumber result;
    if (B.x > 0) {
        result.x = A.x / B.x;
        result.left_e = result.x - ((A.x - A.left_e) / (B.x + B.right_e));
        result.right_e = ((A.x + A.right_e) / (B.x - B.left_e)) - result.x;
    } else {
        cout << "Помилка: дільник <= 0.\n";
        result.x = 0; result.left_e = 0; result.right_e = 0;
    }
    return result;
}


TFazzyNumber operator/(double lhs, TFazzyNumber A) {
    TFazzyNumber result;
    if (A.x > 0) {
        result.x = lhs / A.x;
        result.left_e = result.x - (lhs / (A.x + A.right_e));
        result.right_e = (lhs / (A.x - A.left_e)) - result.x;
    } else {
        cout << "Помилка: число <= 0.\n";
        result.x = 0; result.left_e = 0; result.right_e = 0;
    }
    return result;
}

int main() {

    TFazzyNumber num1, num2, res;

    cout << "---СТРУКТУРИ ---\n";
    cout << "Введіть перше число:\n";
    input(num1);
    cout << "Введіть друге число:\n";
    input(num2);

    res = num1 + num2;
    cout << "\nСума (num1 + num2): ";
    output(res);

    res = num1 - num2;
    cout << "Різниця (num1 - num2): ";
    output(res);

    res = num1 * num2;
    cout << "Добуток (num1 * num2): ";
    output(res);

    res = num1 / num2;
    cout << "Ділення (num1 / num2): ";
    output(res);

    res = 1.0 / num1;
    cout << "Ділення (1 / num1): ";
    output(res);

    return 0;
}
