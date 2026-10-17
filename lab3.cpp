#include <iostream>
#include <cstdio>
#include <windows.h>

using namespace std;

struct TFazzyNumber {
    double left_e;
    double x;
    double right_e;
};

class FuzzyClass {
    private:
    TFazzyNumber object;

    public:
    void init(double le, double val, double re);
    void input();
    void output();
    char* toPChar();

    TFazzyNumber getStruct(){
        return object;
    }
    void setStruct(TFazzyNumber newObj){
        object = newObj;
    }
};

void FuzzyClass::input() {
    cout << "Введіть x (саме число): ";
    cin >> object.x;
    cout << "Введіть e1 (ліву похибку): ";
    cin >> object.left_e;
    cout << "Введіть e2 (праву похибку): ";
    cin >> object.right_e;
}

void FuzzyClass::output() {
    cout << "(" << object.x - object.left_e << ", "
         << object.x << ", "
         << object.x + object.right_e << ")\n";
}

void FuzzyClass::init(double le, double val, double re) {
    object.left_e = le;
    object.x = val;
    object.right_e = re;
}

char* FuzzyClass::toPChar() {
    char* buffer = new char[100]; 
    sprintf(buffer, "(%.2f, %.2f, %.2f)", 
            object.x - object.left_e, 
            object.x, 
            object.x + object.right_e);
    return buffer; 
}

FuzzyClass addFuzzy(FuzzyClass ob1, FuzzyClass ob2) {
    TFazzyNumber A = ob1.getStruct();
    TFazzyNumber B = ob2.getStruct();
    TFazzyNumber result;
    
    result.x = A.x + B.x;
    result.left_e = A.left_e + B.left_e;
    result.right_e = A.right_e + B.right_e;
    
    FuzzyClass resultObj;
    resultObj.setStruct(result);
    return resultObj;
}

FuzzyClass subFuzzy(FuzzyClass ob1, FuzzyClass ob2) {
    TFazzyNumber A = ob1.getStruct();
    TFazzyNumber B = ob2.getStruct();
    TFazzyNumber result;
    
    result.x = A.x - B.x;
    result.left_e = A.left_e + B.left_e; 
    result.right_e = A.right_e + B.right_e;
    
    FuzzyClass resultObj;
    resultObj.setStruct(result);
    return resultObj;
}

FuzzyClass mulFuzzy(FuzzyClass ob1, FuzzyClass ob2) {
    TFazzyNumber A = ob1.getStruct();
    TFazzyNumber B = ob2.getStruct();
    TFazzyNumber result;
    
    result.x = A.x * B.x;
    result.left_e = B.x * A.left_e + A.x * B.left_e - A.left_e * B.left_e;
    result.right_e = B.x * A.right_e + A.x * B.right_e + A.right_e * B.right_e;
    
    FuzzyClass resultObj;
    resultObj.setStruct(result);
    return resultObj;
}

FuzzyClass inverseFuzzy(FuzzyClass ob1) {
    TFazzyNumber A = ob1.getStruct();
    TFazzyNumber result;
    
    if (A.x > 0) {
        result.x = 1.0 / A.x;
        result.left_e = result.x - (1.0 / (A.x + A.right_e));
        result.right_e = (1.0 / (A.x - A.left_e)) - result.x;
    } else {
        cout << "Помилка: число <= 0, дія (1/Ob1) не може бути виконана.\n";
        result.x = 0;
        result.left_e = 0;
        result.right_e = 0;
    }
    
    FuzzyClass resultObj;
    resultObj.setStruct(result);
    return resultObj;
}

FuzzyClass divFuzzy(FuzzyClass ob1, FuzzyClass ob2) {
    TFazzyNumber A = ob1.getStruct();
    TFazzyNumber B = ob2.getStruct();
    TFazzyNumber result;
    
    if (B.x > 0) { 
        result.x = A.x / B.x;
        result.left_e = result.x - ((A.x - A.left_e) / (B.x + B.right_e));
        result.right_e = ((A.x + A.right_e) / (B.x - B.left_e)) - result.x;
    } else {
        cout << "Помилка: дільник <= 0, дія (Ob1/Ob2) не може бути виконана.\n";
        result.x = 0;
        result.left_e = 0;
        result.right_e = 0;
    }
    
    FuzzyClass resultObj;
    resultObj.setStruct(result);
    return resultObj;
}

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    
    FuzzyClass num1, num2, resultObj;

    cout << "Введіть перше нечітке число:\n";
    num1.input();

    cout << "\nВведіть друге нечітке число:\n";
    num2.input();

    resultObj = addFuzzy(num1, num2);
    cout << "\nРезультат додавання:\n";
    resultObj.output();

    resultObj = subFuzzy(num1, num2);
    cout << "Результат віднімання:\n";
    resultObj.output();
    
    resultObj = mulFuzzy(num1, num2);
    cout << "Результат множення:\n";
    cout << resultObj.toPChar() << "\n";

    resultObj = inverseFuzzy(num1);
    cout << "Результат 1/Ob1 (для першого числа):\n";
    resultObj.output();

    resultObj = divFuzzy(num1, num2);
    cout << "Результат ділення (Ob1/Ob2):\n";
    resultObj.output();

    return 0;
}
