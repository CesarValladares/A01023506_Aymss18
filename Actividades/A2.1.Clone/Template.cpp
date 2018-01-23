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

template<class Padre ,class Hijo>

class ClonMovile : public Padre
{
public:
    Padre* clone()
    {
        return new Hijo(dynamic_cast<Hijo&>(*this));
    }
};

class Tablet : public ClonMovile<Moviles,Tablet>
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
};

class Smartphone : public ClonMovile<Moviles,Smartphone>
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
}; 

class Smartwatch : public ClonMovile<Moviles,Smartwatch>
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
};

int main()
{
    Tablet* T1 = new Tablet(5555, 525, "IPAD", "Iñigo", "Apple"); 
    cout << "ANTES"<< endl;
    cout << endl;
    cout << "Tablet 1: "<< *T1->branch << endl;
    /*Tablet T2 = *T1;
    cout << "Tablet 2: "<< *T2.branch << endl;
    cout << endl;
    cout << "DESPUES" << endl;
    cout << "Tablet 1: "<< *T1->branch << endl;
    *T2.branch = "Samsung";
    cout << "Tablet 2: "<< *T2.branch << endl;*/
    return 0; 
}