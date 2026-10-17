#include <iostream>
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
        object =newObj;
    }
};

void FuzzyClass::input() {
    cout << "Введіть x (саме чсило): ";
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
    object.left_e=le;
    object.x=val;
    object.right_e=re;
}

char* FuzzyClass::toPChar() {

}

FuzzyClass addFuzzy(FuzzyClass ob1, FuzzyClass ob2) {
    



    FuzzyClass result;
    // Логіка додавання
    return result;
}

int main() {
    FuzzyClass num1, num2, resultObj;

    cout << "Введіть перше нечітке число:\n";
    num1.input();

    cout << "\nВведіть друге нечітке число:\n";
    num2.input();

    // Додаємо їх через нашу сторонню функцію
    resultObj = addFuzzy(num1, num2);

    cout << "\nРезультат додавання:\n";
    resultObj.output();

    return 0;
}
