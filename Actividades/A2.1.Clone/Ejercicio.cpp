#include <iostream>
#include <string>

using namespace std;

class Moviles 
{
public:
    virtual Moviles* clone() = 0; 
    Moviles(){};
    int* serial_number; 
    int* ID;
    string type; 
    string usuario; 

    Moviles(int serial_number,int ID,string type,string usuario):serial_number(new int(serial_number)), ID(new int(ID)),type(type),usuario(usuario){}

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
    Tablet(){};
    
    string* branch;  

    Tablet(int serial_number, int ID, string type, string usuario, string branch): Moviles(serial_number, ID, type, usuario), branch(new string(branch)){}

    Tablet (const Tablet& temp)
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
    
};

class Smartphone : public Moviles
{
public:
    int* phone_number; 

    Smartphone(int serial_number, int ID, string type, string usuario, int phone_number): Moviles(serial_number, ID, type, usuario), phone_number(new int (phone_number)){}

    Smartphone (const Smartphone& temp)
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
}; 

class Smartwatch : public Moviles
{
public:
    int* hour;

    Smartwatch(int serial_number, int ID, string type, string usuario, int hour): Moviles(serial_number, ID, type, usuario), hour(new int(hour)){}

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
};

int main()
{
    Tablet* T1 = new Tablet(5555, 525, "IPAD", "Iñigo", "Apple"); 
    cout << "ANTES"<< endl;
    cout << endl;
    cout << "Branch 1: "<< *T1->branch << endl;
    cout << "Serial number 1:   " << *T1->serial_number << endl; 
    cout << "ID 1:              " << *T1->ID << endl;
    cout << "Type 1:            " << T1->type << endl;
    cout << "Usuario 1:         " << T1->usuario << endl;
    /*Tablet T2 = *T1;
    cout << "Tablet 2: "<< *T2.branch << endl;
    cout << endl;
    cout << "DESPUES" << endl;
    cout << "Tablet 1: "<< *T1->branch << endl;
    *T2.branch = "Samsung";
    cout << "Tablet 2: "<< *T2.branch << endl;*/
    return 0; 
}