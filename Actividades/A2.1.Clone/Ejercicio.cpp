#include <iostream>
#include <string>

using namespace std;

class Moviles 
{
public:
    virtual Moviles* clone() = 0; 
    int* serial_number; 
    int* ID;
    string type; 
    string usuario; 

    void encender()
    {
        cout << "encendiendo..." << endl;
    }
    void apagar()
    {
        cout << "apagando..." << endl;
    }
    void reiniciar()
    {
        cout << "reiniciando..." << endl;
    }
    void restaurar()
    {
        cout << "restaurando..." << endl;
    }

};
class Tablet : public Moviles
{
public:
    string* branch;  

    Tablet() = default; 

    Tablet (const Moviles& temp)
    {
        branch = new string(*(this->branch));
        serial_number = new int(*(temp.serial_number));
        ID = new int (*(temp.ID));
        type = (temp.type);
        usuario = (temp.usuario);
    }

    Moviles* clone()
    {
        return new Tablet(*this);
    }

    Tablet(string branch) : branch(new string(branch))
    {
        cout << "Branch " << branch << endl;
    }
    
};

class Smartphone : public Moviles
{
public:
    int* phone_number; 
    Moviles* clone()
    {
        return new Smartphone(*this);
    }
    
};
class Smartwatch : public Moviles
{
public:
    int* hour;
    Moviles* clone()
    {
        return new Smartwatch(*this);
    }
    
};

int main()
{
    Tablet* T1 = new Tablet("Apple"); 
    T1->encender(); 
    return 0; 
}