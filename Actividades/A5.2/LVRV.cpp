#include<iostream>
using namespace std;

class Foo{
    int value; 
    int* pointer; 
public: 
    //predefino el valor de value
    explicit Foo(int value = 0) : value(value), pointer(new int[value]){
        cout << "param const" << endl;
    }
    Foo(const Foo& ref){
        cout << "copy const" << endl;
    }

    /*Foo& operator=(const Foo& ref){
        cout << "copy assig" << endl;
        Foo temp(ref);
        swap(value, temp.value);
        swap(pointer, temp.pointer);
        return* this;
    }*/
    Foo(Foo&& temp){}

    Foo& operator = (Foo&& temp){
        cout << "move assig" << endl;
        swap(value, temp.value);
        swap(pointer, temp.pointer);
        return* this;
    }

}; 

int main(){
    Foo a (5);  
    Foo b ;
    b = Foo(5);
    
}