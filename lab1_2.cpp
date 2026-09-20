#include <iostream>
using namespace std;
typedef struct store s;
struct store{
    double first;
    int second;
};

int check(double f, int s){
    if(f>0 && s>0) return 1;
    return 0;
}

void input(s &ob){
    do{
        cout << "Enter price (real number) and quantity (integer): ";
        cin >> ob.first >> ob.second;
        if(check(ob.first,ob.second)==0)
        cout << "Error! Values must be positive\n";
    }while(check(ob.first,ob.second)==0);
}

void output(s ob){
    cout << "Product price: " << ob.first << "\n";
    cout << "Product quantity: " << ob.second << "\n";
} 
double cost(s ob){
    return ob.first * ob.second;
}
double costTwo(s ob,s ob1){
    return cost(ob) + cost(ob1);
}

int main(){


    s ob1, ob2;
    cout << "--- Product 1 ---\n";
    input(ob1);
    
    cout << "--- Product 2 ---\n";
    input(ob2);
    
    cout << "\n--- Results ---\n";
    output(ob1);
    cout << "Cost of the first: " << cost(ob1) << "\n\n";

    output(ob2);
    cout << "Cost of the second: "<< cost(ob2) << "\n\n";

    cout << "Total cost: " << costTwo(ob1, ob2)<< "\n";
return 0;
}