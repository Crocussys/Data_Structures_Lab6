#ifndef BUNCH_H
#define BUNCH_H


class Bunch
{
private:
    int size;
    int count;
    int weight;
    int* array;
public:
    Bunch(int s);
    ~Bunch();
    void append(int elem);
    int get_weight();
    void print();
};

#endif // BUNCH_H
