#include <iostream>

using namespace std;
class Prueba
{

public: 
    int* val;
    int val2;
    Prueba()
    {
        cout << "Default constructor" << endl; 
    }
    Prueba(int val) : val(new int(val)), val2(val)
    {
        cout << "Params " << val << endl;
    }
    Prueba(const Prueba& temp)
    {
        val2 = *(temp.val);
        val = new int (*(temp.val));
    }

};

int main()
{
    Prueba P; 
    Prueba* Z = new Prueba(2);  
    cout << "antes: " << *(Z->val) << endl; 
    Prueba W = *Z;
    cout << "copy: " << *(W.val) << endl;
    *(W.val) = 8; 
    cout << "instancia W: " << *(W.val) << endl;
    cout << "instancia Z: " << *(Z->val) << endl;

    return 0; 
}