#include <iostream>
#include <string>

using namespace std;

class Vehiculo
{
public: 
    virtual void Ensamblado() = 0; 
    virtual void Hojalateria() = 0; 
    virtual void Pintura() = 0; 
    virtual void Entrega() = 0; 
}; 

class DODGE : public Vehiculo
{
public: 
    void Ensamblado()
    { cout << "Ensablando DODGE" << endl; }
    void Hojalateria()
    { cout << "Hojalateria DODGE" << endl; }
    void Pintura()
    { cout << "Pintando DODGE" << endl; }
    void Entrega()
    { cout << "DODGE entregado" << endl; }
}; 

class BMW : public Vehiculo
{
public: 
    void Ensamblado()
    { cout << "Ensablando BMW" << endl; }
    void Hojalateria()
    { cout << "Hojalateria BMW" << endl; }
    void Pintura()
    { cout << "Pintando BMW" << endl; }
    void Entrega()
    { cout << "BMW entregado" << endl; }
}; 

class VV : public Vehiculo
{
public: 
    void Ensamblado()
    { cout << "Ensablando VV" << endl; }
    void Hojalateria()
    { cout << "Hojalateria VV" << endl; }
    void Pintura()
    { cout << "Pintando VV" << endl; }
    void Entrega()
    { cout << "VV entregado" << endl; }
}; 

class NISSAN : public Vehiculo
{
public: 
    void Ensamblado()
    { cout << "Ensablando NISSAN" << endl; }
    void Hojalateria()
    { cout << "Hojalateria NISSAN" << endl; }
    void Pintura()
    { cout << "Pintando NISSAN" << endl; }
    void Entrega()
    { cout << "NISSAN entregado" << endl; }
}; 

class Creator
{

    template<class Tipo>
    Tipo* factoryMethod()
    {
        return new Tipo;
    }

public:
    template<class Tipo>
    Tipo* create()
    {
        Tipo* Temp;
        Temp = factoryMethod<Tipo>();
        Temp->Ensamblado();
        Temp->Hojalateria();
        Temp->Pintura();
        Temp->Entrega();

        return Temp;
    }
};


int main ()
{
    Creator* c = new Creator;
    Vehiculo* c1 = c->create<DODGE>(); 
    return 0;
}