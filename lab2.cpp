#include <iostream>
#include <cctype>

using namespace std;
int check(int size) {
    if (size > 0 && size <= 100) return 1;
    return 0;
}

template <typename Type>
void input(Type arr[], int size){
    cout << "Enter "<< size << " elements of the array separated by space:\n";
    for (int i=0; i<size ; i++){
        while(true){
            cin >> arr[i];
            
            if (cin.fail()) {
                cout << "Error! Enter a number, not letters. Try again for element #" << i + 1 << ": ";
                cin.clear();             
                cin.ignore(10000, '\n');
            } else {
                break;
            }
        }
    }
}

template <typename Type>
void output(Type arr[], int size){
    cout << "Your array: ";
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
        if (isalpha(str[i]) || str[i] == '\''){
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
        cout << "Enter the number of elements for the INT array ";
        cin >> size;
        if (cin.fail()) {
            cout << "Error! Enter a number, not letters.\n";
            cin.clear();
            cin.ignore(10000, '\n');
            size = 0; 
        }
        else if(check(size) == 0) {
            cout << "Error! Incorrect size.\n";
        }
    }while (check(size) == 0);

    int intArr[size];
    input(intArr, size);
    output(intArr, size);
    cout << "Maximum element (int): "<< findMax(intArr,size)<< "\n\n";

    do {
        cout << "Enter the number of elements for the DOUBLE array ";
        cin >> size;
        if (cin.fail()) {
            cout << "Error! Enter a number, not letters.\n";
            cin.clear();
            cin.ignore(10000, '\n');
            size = 0;
        }
        else if(check(size) == 0) {
            cout << "Error! Incorrect size.\n";
        }
    }while (check(size) == 0);

    double doubleArr[size];
    input(doubleArr, size);
    output(doubleArr, size);
    cout << "Maximum element (double): "<< findMax(doubleArr,size)<< "\n\n";

    char text[256];
    cout << "Enter a sentence in English (with spaces): ";
    cin.ignore(10000, '\n');
    cin.getline(text, 256);
    cout << "Entered string: " << text << "\n";
    cout << "Maximum word length: " << findMax(text) << "\n";
    // ведення данів , якщо вводиш 1.5 треба щоб просило знову ввести, меню зроби, мішаний масив(з числових)
    return 0;
}
