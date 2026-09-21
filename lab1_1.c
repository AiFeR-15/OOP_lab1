#include <stdio.h>

typedef struct store s;
struct store{
    double first;
    int second;
};

int check(double f, int s){
    if(f>0 && s>0) return 1;
    return 0;
}

void input(s *ob){
    int flag;
    do{
        printf("Enter price (real number) and quantity (integer): ");
        flag = scanf("%lf %d", &ob->first, &ob->second);

        if(flag !=2){
            printf("Error! Please enter numbers only.\n");
            while (getchar() != '\n');
            ob->first = 0;
            ob->second = 0;
        }
        else if(check(ob->first,ob->second)==0){
        printf("Error! Values must be positive\n");
    }
    }while(check(ob->first,ob->second)==0 );
}

void output(s ob){
    printf("Product price: %.2lf\n", ob.first);
    printf("Product quantity: %d\n", ob.second);
} 
double cost(s ob){
    return (double) ob.first * ob.second;
}
double costTwo(s ob,s ob1){
    return cost(ob) + cost(ob1);
}

int main(){


    s ob1, ob2;
    printf("--- Product 1 ---\n");
    input(&ob1);
    
    printf("--- Product 2 ---\n");
    input(&ob2);
    
    printf("\n--- Results ---\n");
    output(ob1);
    printf("Cost of the first: %.2lf\n\n", cost(ob1));

    output(ob2);
    printf("Cost of the second: %.2lf\n\n", cost(ob2));

    printf("Total cost: %.2lf\n", costTwo(ob1, ob2));
return 0;
}