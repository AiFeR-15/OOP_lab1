#include <iostream>
using namespace std;
int check(int size) {
    if (size > 0 && size <= 100) return 1;
    return 0;
}

template <typename Type>
void input(Type arr[], int size){
    cout << "Введіть "<< size << " елементів маисву через пробіл:\n";
    for (int i=0; i<size ; i++){
        cin >> arr[i];
    }
}

template <typename Type>
void output(Type arr[], int size){
    cout << "Ваш масив: ";
    for (int i = 0; i<size; i++){
        cout << arr[i]<< ' ';
    }
    cout << "\n";
}

template <typename Type>
Type findMax(Type arr[], int size){
    Type maxElem = arr[0];
    for(int i=1; i<size; i++){
        if(arr[i]>maxElem) maxElem=arr[i];
    }
    return maxElem;
}

int findMax(const char* str ){
    int maxLen=0;
    int countLen=0;

    for(int i=0; str[i] != '\0'; i++){
        if (str[i] != ' '){
            countLen++;
        }
        else{
            if(countLen>maxLen) maxLen=countLen;
            countLen=0;
        }

    }
    if(countLen>maxLen) maxLen=countLen;
    return maxLen;
}

int main(){
    int size;

    do {
        cout << "Введіть к-сть елементів для масиву INT ";
        cin >> size;
        if(check(size)==0) cout << "Поимлка! Некоректний розмір.\n";
    }while (check(size) == 0);

    int intArr[size];
    input(intArr, size);
    output(intArr, size);
    cout << "Максимальний елемнет (int): "<< findMax(intArr,size)<< "\n\n";

    do {
        cout << "Введіть к-сть елементів для масиву DOUBLE ";
        cin >> size;
        if(check(size)==0) cout << "Поимлка! Некоректний розмір.\n";
    }while (check(size) == 0);

    int doubleArr[size];
    input(doubleArr, size);
    output(doubleArr, size);
    cout << "Максимальний елемнет (double): "<< findMax(doubleArr,size)<< "\n\n";
    return 0;
}