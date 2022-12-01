#include <iostream>
#include "bunch.h"

using namespace std;

Bunch::Bunch(int s)
{
    size = s;
    count = 0;
    weight = 0;
    array = new int [size];
}
Bunch::~Bunch()
{
    size = 0;
    count = 0;
    weight = 0;
    delete [] array;
}
void Bunch::append(int elem)
{
    if (count >= size - 1){
        throw;
    }
    weight += elem;
    array[count] = elem;
    count++;
}
int Bunch::get_weight()
{
    return weight;
}
void Bunch::print()
{
    cout << "Вес кучи: " << weight << endl;
    cout << "Камни: ";
    for (int i = 0; i < count; i++){
        cout << array[i] << " ";
    }
    cout << endl;
}
