#include <iostream>

using namespace std;

class IntCollection;

class Iterator{
protected:
    IntCollection* collection;
    int cont;
public:
    virtual int next() = 0;
    virtual bool hasNext() = 0;
};

class IntCollection{
public:
    virtual void add(int element) = 0;
    virtual int at(int position) = 0;
    virtual Iterator* getIterator() = 0;
    virtual int getNumElements() = 0;
};

class IntArray;

class ArrayIterator : public Iterator{
public:
    ArrayIterator(IntArray* intArray){
        collection = (IntCollection*)intArray;
        cont = 0;
    }

    int next(){
        return collection->at(cont++);
    }

    bool hasNext(){
        if (cont >= collection->getNumElements() ){
            return false;
        }
        else{
            return true;
        }
    }
};

class IntArray : public IntCollection{
protected:
    int* a; 
    int size;
    int numElements;

public:

    IntArray(){

        size = 10;
        a = new int[size];
        numElements = 0;
    }

    void add(int element){

        if(numElements >= size)
        {
            cout << "Ya no hay espacio!!" << endl;
            return;
        }
        
        a[numElements++] = element;
        
    }

    int at(int position){

        if( 0 > position >= size)
        {
            cout << "Indice no valido" << endl;
            throw "out of range";
        }else {
            return a[position];
        }
    }

    Iterator* getIterator(){
        
        return new ArrayIterator(this);
    }

    int getNumElements(){
        return numElements;
    }
};

int main(){

    IntCollection* c = new IntArray;
    c->add(4);
    c->add(10);
    c->add(50);
    c->add(59);
    c->add(78);

    Iterator* i = c->getIterator();

    while(i->hasNext()){
        cout << i->next() << endl;
        
    }


    return 0;
}