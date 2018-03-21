#include <iostream>

using namespace std;

template <class T>
class Collection{
public:
    virtual void add(int element) = 0;
    virtual int at(int position) = 0;
    virtual Iterator* getIterator() = 0;
    virtual int getNumElements() = 0;
    
};

template<class T>
class Iterator{

    Collection<T> c;

public:
    Iterator(Collection<T> cc){
        c=cc;
    }

    bool hasNext()
    {
        if()
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

