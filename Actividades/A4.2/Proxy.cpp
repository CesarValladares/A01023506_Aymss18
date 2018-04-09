#include <iostream>
#include <stdexcept>

using namespace std;

class ArrayInts;
class Proxy{
    ArrayInts* a;
    int idx;
public:
    Proxy(ArrayInts* a, int idx){
        this->a=a;
        this->idx = idx;
    }
    void operator=(int);
};

class ArrayInts{
    int* array;
    int size;
public:
    ArrayInts(){
        int size = 100;
        array = new int[size];
    }
    Proxy operator[](int idx)
    {
        if(idx < 0){
            cout << "no hay indices negativos" << endl;
        }
        return Proxy(this, idx);
    }
    int& setGet(int idx){
        return array[idx];
    }
};

void Proxy::operator=(int value){
    if(value < 0){
        cout << "no hay valores negativos " << endl;
    }
    else{
        a->setGet(idx) = value;
    }
}

int main(){

    ArrayInts a;
    a[-3] = 5;

    return 0;
}