#include <iostream>
#include "bunch.h"

using namespace std;

int input()
{
    int n;
    while (true){
        if ((cin >> n).good() and n >= 0){
            break;
        }
        if (cin.fail()){
            cin.clear();
        }
        cout << "Нет. Введите число" << endl;
        cin.ignore(100, '\n');
    }
    return n;
}

int main()
{
    cout << "Сколько будет камней?" << endl;
    int n = input();
    cout << endl;
    cout << "Введите веса камней" << endl;
    int* array = new int [n];
    for (int i = 0; i < n; i++){
        array[i] = input();
    }
    int buffer[3] = {0, 0, 0};
    for (int i = 0; i < n; i++){
        for (int j = 0; j < 3; j++){
            if (array[i] > buffer[j]){
                for (int k = 2; k > j; k--){
                    buffer[k] = buffer[k - 1];
                }
                buffer[j] = i;
                break;
            }
        }
    }
    cout << endl;
    Bunch bnc1(n);
    Bunch bnc2(n);
    bnc1.append(array[buffer[0]]);
    bnc2.append(array[buffer[1]]);
    bnc2.append(array[buffer[2]]);
    array[buffer[0]] = -1;
    array[buffer[1]] = -1;
    array[buffer[2]] = -1;
    for (int i = 0; i < n; i++){
        int elem = array[i];
        if (elem == -1){
            continue;
        }
        if (bnc1.get_weight() < bnc2.get_weight()){
            bnc1.append(elem);
        }else{
            bnc2.append(elem);
        }
    }
    int min;
    int max;
    int w1 = bnc1.get_weight();
    int w2 = bnc2.get_weight();
    if (w1 > w2){
        max = w1;
        min = w2;
    }else{
        max = w2;
        min = w1;
    }
    if (min * 1.5 < max){
        cout << "Нельзя сделать такое разбиение" << endl << endl;
    }else{
        bnc1.print();
        cout << endl;
        bnc2.print();
        cout << endl;
    }
    delete [] array;
    return 0;
}
