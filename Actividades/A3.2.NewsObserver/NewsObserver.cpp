#include <iostream>
#include <string>
#include <vector>

using namespace std; 

class Observer {
public:
    virtual void update(string news, string sub) = 0;
};

class ConcreteObserver : Observer{
public:
    string name; 
    string news;

    ConcreteObserver(string n){
        this->name = n; 
    }
    void update(string n, string sub)
    {
        this->news = n;
        cout << name << ": '" << sub << " Dice: "<< news << "'" << endl; 
    }
}; 

class Subject {
    vector<ConcreteObserver*> Observers; 
public:
    void attach(ConcreteObserver *o){
        Observers.push_back(o); 
    }
    void detach(ConcreteObserver *o){
        for (int i = 0; i < Observers.size(); i++)
        {
            if (o->name == Observers[i]->name){
                cout << "Se eliminara: " << o->name << endl;
                Observers.erase(Observers.begin() + i);
            }
        }
    }
    void notifyAll(string news, string sub){
        for (int i = 0; i < Observers.size(); i++){
            Observers[i]->update(news, sub);
        }
    }
};

class ConcreteSubject : public Subject{
public: 
    string name;

    ConcreteSubject(string n){
        this->name = n; 
    }
    void Publicar(string news){
        notifyAll(news, name);
    }
};

int main(){

    ConcreteSubject Trump("Trump");
    ConcreteSubject Anaya("Anaya");
    ConcreteSubject Meade("Meade"); 
    ConcreteSubject Zavala("Zavala"); 
    ConcreteSubject AMLO("AMLO");

    ConcreteObserver MVSNews("MVSNews"); 
    ConcreteObserver TelevisaNews("TelevisaNews"); 
    ConcreteObserver AztecaNoticias("AztecaNoticias");

    Trump.attach(&MVSNews);
    Trump.attach(&TelevisaNews);
    Trump.attach(&AztecaNoticias);

    Anaya.attach(&TelevisaNews);

    AMLO.attach(&TelevisaNews);
    AMLO.attach(&AztecaNoticias);

    Trump.Publicar("Hola");

    //Anaya.Publicar("Adios");
    //AMLO.Publicar("Buenos dias");

    Trump.detach(&TelevisaNews);

    Trump.Publicar("Adios");


    return 0;
}