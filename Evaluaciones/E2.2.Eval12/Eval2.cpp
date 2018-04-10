#include <iostream>
#include <vector>
#include <string>

using namespace std;

class videojuego{
public: 
    int serie;
    float precio;
    string name; 
    string company;
    string console; 

    videojuego()=default; 

    void Concepcion(){
        cout << "Concepción..." << endl;
    }

    void Diseno(){
        cout << "Diseño..." << endl;
    }

    void Planificacion(){
        cout << "Planificación..." << endl; 
    }

    void Produccion(){
        cout << "Producción..." << endl;
    }

    void PuebasAcpt(){
        cout << "Puebas de aceptación..." << endl;
    }
    void setPrice(float p){
        precio = p; 
    }
};


//Categorias
class Estrategia : public videojuego {
protected: 
    Estrategia() = default;
};

class Aventura : public videojuego{
protected: 
    Aventura() = default;
};

class Aprendizaje :public videojuego{
protected: 
    Aprendizaje() = default;
};

//ESTRATEGIA
class Lucha : public Estrategia{
public:
    Lucha(){
        name = "Marvel vs Capcom";
        company = "GamesCom";
        console = "PlayStation";
    }
};

class Arcade : public Estrategia{
public: 
    Arcade(){
        name = "Metal Slug";
        company = "CG";
        console = "GameBoy";
    }
};

//AVENTURA 
class Plataforma : public Aventura{
public:
    Plataforma(){
        name = "Super Mario 64";
        company = "Nintendo";
        console = "Nintendo 64";   
    }
};

class Grafica : public Aventura{
public: 
    Grafica(){
        name = "Grafica";
        company = "GraficaComp";
        console = "GragicConsole";
    }
};

//APRENDIZAJE
class Idiomas : public Aprendizaje{
public: 
    Idiomas(){
        name = "Pipo";
        company = "PipoGames";
        console = "PC";
    }
};

class Musica : public Aprendizaje{
public:
    Musica(){
        name = "Guitar Hero"; 
        company = "MusicGames";
        console = "XBOX";
    }
};

//ITERADOR

template<class T>
class Iterator;

template<class T>
class Collection{
public: 
    T* array; 
    int max; 
    int act;

    friend class Iterator<T>; 

    Collection(){
        max = 15;
        act = 0; 
        array = new T[max]; 
    }

    void add(T game){
        if (act <= max){
            array[act++] = game; 
        }
        else{
            cout << "Espacio en el inventario insuficiente" << endl;
        }
    }

    T at (int position){
        if (0 > position){
            cout << "índice no valido" << endl; 
            throw "out of range"; 
        }
    }

    int getNumElements(){
        return act;
    }

    void imprimirColl(){
        for (int i = 0; i < act; i++){
            cout << "name = " << array[i]->name <<
             ", " << "Company = " << array[i]->company << 
             ",  " << "Console = " << array[i]->console <<
             ",  " << "Price = " << array[i]->precio << endl;
        }
    }

    Iterator<T>* getIterator();
};

template<class T>
class Iterator{
protected:
    Collection<T> collection;
    int cont = 0;
public:
    Iterator(const Collection<T>& collection) : collection(collection){}


    virtual T next(){
        T a  = collection.at(cont);
        cont++;
        return a; 
    }
    virtual bool hasNext(){
        if (cont < collection.act){
            return true; 
        }else{
            return false; 
        }
    }
};

template<class T>

Iterator<T>* Collection<T>:: getIterator(){
    return new Iterator<T>(*this);
} 

class Inventario{
protected: 
    int i = 1;
    int t = 0; 
public: 
    Inventario(){}
    Collection<videojuego*> inv; 
    Iterator<videojuego*> *it; 

    void crearjuego(){
        Inventario* inventario = new Inventario(); 
    }
    void addGame (videojuego* v){
        it = inv.getIterator();
        inv.add(v);
        i++;
    }

    int getElements(){
        return inv.getNumElements();
    }

    void imprimir(){
        inv.imprimirColl();
    }

};

//COMMANDS

class Command
{
public:
	virtual void execute() = 0;
};
 
// Receiver 
class Accion 
{
public:
	void undo() {
		cout << "undo" << endl;
	}
	void redo() {
		cout << "redo" << endl;
	}
}; 

class undoCommand : public Command 
{
public:
    undoCommand(Accion *Accion) : mAction(Accion) {}
	void execute(){
		mAction->redo();
	}
private:
	Accion *mAction;
};
 
class redoCommand : public Command 
{
public:
        redoCommand(Accion *Accion) : mAction(Accion) {}
	void execute(){
		mAction->undo();
	}
private:
	Accion *mAction;
};

// Invoker 
// Stores the ConcreteCommand object 
class RemoteControl 
{
public:
	void setCommand(Command *cmd) {
		mCmd = cmd;
	}

	void buttonPressed() {
		mCmd->execute();
	} 
private:
	Command *mCmd;
};
 


int main()
{
    /*Inventario* uno = new Inventario();

    Lucha* g1 = new Lucha(); 
    Idiomas* g2 = new Idiomas();
    Musica* g3 = new Musica();

    g1->setPrice(12.8);
    g2->setPrice(20.4);
    g3->setPrice(25.6);


    uno->addGame(g1);
    uno->addGame(g2);
    uno->addGame(g3);

    cout << uno->getElements() << endl; 

    uno->imprimir();

    //receiver
    Accion * accion = new Accion;

    //concrete commands
    redoCommand *redo = new redoCommand(accion);
    undoCommand *undo = new undoCommand(accion);

    // invoker objects
	RemoteControl *control = new RemoteControl;

    control->setCommand(redo);
    control->buttonPressed();*/
    
    system("clear");


    Inventario* uno = new Inventario();

    cout << "Bienvenido a nuestro sistema de inventario, ¿qué desea hacer?" << endl;
    cout << 
    "1.- Agregar un nuevo juego al inventario\n"
    "2.- Borrar un juego del invantario\n" 
    "3.- Revisar inventario\n" 
    "4.- Buscar Juego\n" << endl;

    int a;
    cin >> a;

    system("clear");

    switch(a){
        case 1:
            cout << "Agregar juego" << endl;
            break;
        case 2:
            cout << "Borrar juego" << endl;
            break;
        case 3:
            cout << "Revisar" << endl;
            break;
        case 4:
            cout << "Buscar" << endl;
    }



  
    return 0;
}