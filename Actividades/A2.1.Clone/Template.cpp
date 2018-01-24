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

// Opcion 1
template<class Padre ,class Hijo> //CRTP (Currently Recurrying Template Patern)

class ClonMovile : public Padre
{
public:
    Padre* clone()
    {
        return new Hijo(dynamic_cast<Hijo&>(*this));
    }
};

// Opcion 2
template <class Padre, class Subclass>
class CloneCRTP : public Padre
{
public: 
    Padre* clone()
    {
        return new Subclass (dynamic_cast<Subclass&>(*this));
    }
    
};

class Laptop : public CloneCRTP<Moviles, Laptop>
{
public:
    void doSomething(){
        cout << "Doing something..." << endl;
    }
};
//-----------------------------------------------------------------------

class Tablet : public ClonMovile<Moviles,Tablet>
{
public:
    Tablet(){};
    
    string* branch;  

    Tablet(int sn, int i, string ty, string us, string branch): branch(new string (branch))
    {
        serial_number = &sn; 
        ID = &i;
        type = ty; 
        user = us; 
        branch = branch;
    }

    Tablet (const Tablet& temp)
    {
        branch = new string(*(temp.branch));
        serial_number = new int(*(temp.serial_number));
        ID = new int (*(temp.ID));
        type = (temp.type);
        user = (temp.user);
    }   
};

class Smartphone : public ClonMovile<Moviles,Smartphone>
{
public:

    Smartphone(){};
    
    int* phone_number; 

    Smartphone(int sn, int i, string ty, string us, int phone_number): phone_number(new int (phone_number))
    {
        serial_number = &sn; 
        ID = &i;
        type = ty; 
        user = us; 
        phone_number = phone_number;
    }

    Smartphone (const Smartphone& temp)
    {
        phone_number = new int(*(temp.phone_number));
        serial_number = new int(*(temp.serial_number));
        ID = new int (*(temp.ID));
        type = (temp.type);     
        user = (temp.user);
    }
}; 

class Smartwatch : public ClonMovile<Moviles,Smartwatch>
{
public:
    int* hour;

    Smartwatch(int sn, int i, string ty, string us, int hour): hour(new int (hour))
    {
        serial_number = &sn; 
        ID = &i;
        type = ty; 
        user = us; 
        hour = hour;
    }

    Smartwatch (const Smartwatch &temp)
    {
        hour = new int(*(temp.hour));
        serial_number = new int(*(temp.serial_number));
        ID = new int (*(temp.ID));
        type = (temp.type);
        user = (temp.user);
    }
};

int main()
{
    //Tablet
    Tablet * T1 = new Tablet();
    T1->branch = new string("Apple");
    T1->serial_number = new int(5585);
    T1->ID = new int(6565656);
    T1->type = "IPAD Pro";
    T1->user = "César";

    cout << "-----------------Tablet 1---------------------" << endl;
    T1->encender();
    T1->apagar();
    T1->reiniciar();
    T1->restaurar();

    cout << "T1 Branch:         " << *T1->branch << endl;
    cout << "T1 Serial number:  " << *T1->serial_number << endl;
    cout << "T1 ID:             " << *T1->ID << endl;
    cout << "T1 Type:           " << T1->type << endl; 
    cout << "T1 User:           " << T1->user << endl;
    cout << endl;

    Tablet* T2 = dynamic_cast<Tablet*>(T1->clone());  

    
    cout << "-----------------CLONE T1---------------------" << endl;
    T2->serial_number = new int(5584545);
    T2->user = "Armando";
    cout << "T2 Branch:         " << *T2->branch << endl;
    cout << "T2 Serial number:  " << *T2->serial_number << endl;
    cout << "T2 ID:             " << *T2->ID << endl;
    cout << "T2 Type:           " << T2->type << endl; 
    cout << "T2 User:           " << T2->user << endl;  
    cout << endl;

    //Smartphone
    Smartphone * S1 = new Smartphone();
    S1->phone_number = new int(55365588);
    S1->serial_number = new int(5585);
    S1->ID = new int(6565656);
    S1->type = "Samgung Galaxy";
    S1->user = "César";

    cout << "--------------Smartphone 1---------------------" << endl;
    S1->encender();
    S1->apagar();
    S1->reiniciar();
    S1->restaurar();

    cout << "S1 Phone number:   " << *S1->phone_number << endl;
    cout << "S1 Serial number:  " << *S1->serial_number << endl;
    cout << "S1 ID:             " << *S1->ID << endl;
    cout << "S1 Type:           " << S1->type << endl; 
    cout << "S1 User:           " << S1->user << endl;
    cout << endl;

    Smartphone* S2 = dynamic_cast<Smartphone*>(S1->clone());

    cout << "-----------------CLONE S1---------------------" << endl;
    S2->serial_number = new int(5584545);
    S2->phone_number = new int(558855);
    S2->user = "Armando";
    cout << "S2 Branch:         " << *S2->phone_number << endl;
    cout << "S2 Serial number:  " << *S2->serial_number << endl;
    cout << "S2 ID:             " << *S2->ID << endl;
    cout << "S2 Type:           " << S2->type << endl; 
    cout << "S2 User:           " << S2->user << endl;  
    cout << endl;

    cout << "-----------------------------------------------" << endl;

    Moviles* m = new Laptop; 
    dynamic_cast<Laptop*>(m)->doSomething();

    return 0; 
}