#include <iostream>
#include <string>

using namespace std;

template <int n>//recibe enteros 
class Repeat : public Repeat<n+1>
{
public: 
    Repeat()
    {
        cout << n << endl;
    }
}; 

template <>
class Repeat <100> //limite de la lista
{
public: 
    Repeat()
    {
        cout << 100 << endl;
    }
}; 

int main ()
{
    Repeat<0> r;
    return 0; 
}