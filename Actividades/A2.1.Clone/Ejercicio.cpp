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

    }
    
};

class Smartphone : public Moviles
{
public:
    int* phone_number; 

    Smartphone (const Moviles& temp)
    {
        phone_number = new int(*(this->phone_number));
        serial_number = new int(*(temp.serial_number));
        ID = new int (*(temp.ID));
        type = (temp.type);
        usuario = (temp.usuario);
    }

    Moviles* clone()
    {
        return new Smartphone(*this);
    }
    
    Smartphone(int phone_number) : phone_number(new int(phone_number))
    {

    }

}; 

class Smartwatch : public Moviles
{
public:
    int* hour;

    Smartwatch (const Moviles& temp)
    {
        hour = new int(*(this->hour));
        serial_number = new int(*(temp.serial_number));
        ID = new int (*(temp.ID));
        type = (temp.type);
        usuario = (temp.usuario);
    }

    Moviles* clone()
    {
        return new Smartwatch(*this);
    }
    
    Smartwatch(int hour) : hour(new int(hour))
    {

    }

};

int main()
{
    Tablet* T1 = new Tablet("Apple"); 
    cout << "ANTES"<< endl;
    cout << endl;
    cout << "Tablet 1: "<< *T1->branch << endl;
    Tablet T2 = *T1;
    cout << "Tablet 2: "<< *T2.branch << endl;
    cout << endl;
    cout << "DESPUES" << endl;
    cout << "Tablet 1: "<< *T1->branch << endl;
    *T2.branch = "Samsung";
    cout << "Tablet 2: "<< *T2.branch << endl;
    return 0; 
}