#include <iostream>
using namespace std;

struct store{
    double first;
    int second;

    int check();
    void input();
    void output();
    double cost();
    double costTwo(store other);
};

int store::check(){
    if(first>0 && second>0) return 1;
    return 0;
}

void store::input(){
    do{
        cout << "Enter price (real number) and quantity (integer): ";
        cin >> first >> second;
        if(check()==0)
        cout << "Error! Values must be positive\n";
    }while(check()==0);
}

void store::output(){
    cout << "Product price: " << first << "\n";
    cout << "Product quantity: " << second << "\n";
}
double store::cost(){
    return first * second;
}
double store::costTwo(store other){
    return cost() + other.cost();
}

int main(){


    store ob1, ob2;
    cout << "--- Product 1 ---\n";
    ob1.input();
    
    cout << "--- Product 2 ---\n";
    ob2.input();
    
    cout << "\n--- Results ---\n";
    ob1.output();
    cout << "Cost of the first: " << ob1.cost() << "\n\n";

    ob2.output();
    cout << "Cost of the second: "<< ob2.cost() << "\n\n";

    cout << "Total cost: " << ob1.costTwo(ob2)<< "\n";
return 0;
}