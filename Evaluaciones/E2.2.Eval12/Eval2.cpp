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
    void agregarvideojuego (videojuego* v){
        it = inv.getIterator();
        inv.add(v);
        i++;
    }

    int getElements(){
        return inv.getNumElements();
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
    Inventario* uno = new Inventario();

    Lucha* g1 = new Lucha(); 
    Idiomas* g2 = new Idiomas();
    Musica* g3 = new Musica();

    uno->agregarvideojuego(g1);
    uno->agregarvideojuego(g2);
    uno->agregarvideojuego(g3);

    cout << uno->getElements() << endl; 

    //receiver
    Accion * accion = new Accion;

    //concrete commands
    redoCommand *redo = new redoCommand(accion);
    undoCommand *undo = new undoCommand(accion);

    // invoker objects
	RemoteControl *control = new RemoteControl;

    control->setCommand(redo);
    control->buttonPressed();


  
    return 0;
}