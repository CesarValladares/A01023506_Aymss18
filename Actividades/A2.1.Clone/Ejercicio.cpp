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
    string user; 

    Moviles(int serial_number,int ID,string type,string user):serial_number(new int(serial_number)), ID(new int(ID)),type(type),user(user){}

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

    Tablet(int serial_number, int ID, string type, string user, string branch): Moviles(serial_number, ID, type, user), branch(new string(branch)){}

    Tablet (const Tablet& temp)
    {
        branch = new string(*(temp.branch));
        serial_number = new int(*(temp.serial_number));
        ID = new int (*(temp.ID));
        type = (temp.type);
        user = (temp.user);
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

    Smartphone(int serial_number, int ID, string type, string user, int phone_number): Moviles(serial_number, ID, type, user), phone_number(new int (phone_number)){}

    Smartphone (const Smartphone& temp)
    {
        phone_number = new int(*(temp.phone_number));
        serial_number = new int(*(temp.serial_number));
        ID = new int (*(temp.ID));
        type = (temp.type);
        user = (temp.user);
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

    Smartwatch(int serial_number, int ID, string type, string user, int hour): Moviles(serial_number, ID, type, user), hour(new int(hour)){}

    Smartwatch (const Smartwatch& temp)
    {
        hour = new int(*(temp.hour));
        serial_number = new int(*(temp.serial_number));
        ID = new int (*(temp.ID));
        type = (temp.type);
        user = (temp.user);
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
    cout << "Usuario 1:         " << T1->user << endl;
    Tablet T2 = *T1;
    cout << "Tablet 2: "<< *T2.branch << endl;
    cout << endl;
    cout << "DESPUES" << endl;
    cout << "Tablet 1: "<< *T1->branch << endl;
    *T2.branch = "Samsung";
    cout << "Tablet 2: "<< *T2.branch << endl;
    return 0; 
}