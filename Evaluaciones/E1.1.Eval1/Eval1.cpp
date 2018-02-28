/*
César Armando Valladares
A01023506
Evaluacion 1 Analisis y Modelación de Sistemas de Software
*/
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

class Correo {
public:
    string from;
    string to; 
    string subject;
    string body;

    Correo(string f, string t, string s, string b){
        from = f;
        to = t;
        subject = s; 
        body = b; 
    }
};

class SMS {
public:
    string telefono;
    string texto;

    SMS(string t, string text){
        telefono = t; 
        texto = text;
    }
};

class Llamada {
public:
    string telefono;
    string nombre;
    string mensaje;

    Llamada(string t, string n, string m){
        telefono = t; 
        nombre = n; 
        mensaje = m; 
    }
};

//class Command
class Command{
public:
    virtual void send()=0;
};

//Receiver 

class receiver {
public: 
    void sendCorreo(){
        cout << "Se envió un Correo" << endl;
    }
    void sendSMS(){
        cout << "Se envió un SMS" << endl;
    }
    void sendLlamada(){
        cout << "Se envió una Llamada" << endl;
    }
};

class Usuario : public receiver{

public:
    string id;
    string nombre;
    string apellido;
    string forma_contacto;
    string mail;
    string phone_num; 
    string calle; 
    string numero; 
    string colonia;
    
    static Usuario* instance;

    Usuario(){}
    Usuario(string i, string n, string a, string fm, string m, string pm, string c, string num, string col){
        id = i;
        nombre = n; 
        apellido = a; 
        forma_contacto = fm;
        mail = m; 
        phone_num = pm; 
        calle = c; 
        numero = num; 
        colonia = col;
    }

    static Usuario* getInstance(){
        if(instance == 0){
            instance = new Usuario();
        }
        return instance;
    }
};

Usuario* Usuario::instance = 0; 

// Command enviar por correo
class SendEmail : public Command {
public:
    SendEmail(Usuario *usuario) : mUsuario(usuario){}
    void send(){
        mUsuario->sendCorreo();
    }
private: 
    Usuario *mUsuario;
};

//Command enviar SMS
class SendSMS : public Command{
public: 
    SendSMS(Usuario *usuario) : mUsuario(usuario){}
    void send(){
        mUsuario->sendSMS();
    }
private: 
    Usuario *mUsuario;
};

//Command enviar llamada
class SendLlamada : public Command{
public: 
   SendLlamada(Usuario *usuario) : mUsuario(usuario){}
    void send(){
        mUsuario->sendLlamada();
    }
private: 
    Usuario *mUsuario;
};

//Invoker 
class Invoker {
public: 
    void setCommand(Command *cmd){
        mCmd = cmd;
    }

    void buttonPressed(){
        mCmd->send();
    }
private:
    Command *mCmd;
};

vector<Usuario> Usuarios;

void leerArchivo(string archivo){
    ifstream arch;
    arch.open(archivo);

    while (arch){
        string linea; 

        //obtener id
        string id;
        getline(arch, id, ',');
        //obtener nombre 
        string nombre;
        getline(arch, nombre, ',');
        //obtener apellido
        string apellido;
        getline(arch, apellido, ',');
        //obtener forma de contacto
        string forma_contacto;
        getline(arch, forma_contacto, ',');
        //obtener mail
        string mail;
        getline(arch, mail, ',');
        // obtener numero telefono
        string phone_num;
        getline(arch, phone_num, ',');
        //obtener calle 
        string calle;
        getline(arch, calle, ',');
        //obtener numero 
        string numero;
        getline(arch, numero, ',');
        //obtener colonia 
        string colonia;
        getline(arch, colonia);

        Usuario a(id,nombre,apellido,forma_contacto,mail,phone_num,calle,numero,colonia);
        Usuarios.push_back(a);
    }
}

void imprimeUsuarios(){

    for (int i = 0 ; i < Usuarios.size()-1; i++){
        cout << "id: " << Usuarios[i].id;
        cout << "  Nombre: " << Usuarios[i].nombre;
        cout << "  Apellido: " << Usuarios[i].apellido;
        cout << "  Forma de contacto: " << Usuarios[i].forma_contacto;
        cout << "  Mail: " << Usuarios[i].mail;
        cout << "  Numero telefono: " << Usuarios[i].phone_num;
        cout << "  Calle: " << Usuarios[i].calle;
        cout << "  Numero: " << Usuarios[i].numero;
        cout << "  Colonia: " << Usuarios[i].colonia;
        cout << endl;
    }
}



int main(){

    leerArchivo("customers.txt");

    //Receiver 
    Usuario *usuario = new Usuario;

    //concrete Command objects
    SendEmail *sendE = new SendEmail(usuario);
    SendSMS *sendsms = new SendSMS(usuario);
    SendLlamada *sendllamada = new SendLlamada(usuario);

    //invoker objects 
    Invoker *control = new Invoker;

    //execute 
    for (int i = 0 ; i < Usuarios.size()-1 ; i++){
        if (Usuarios[i].forma_contacto == "mail"){
            control->setCommand(sendE);
            control->buttonPressed();
        }
        else if(Usuarios[i].forma_contacto == "sms"){
            control->setCommand(sendsms);
            control->buttonPressed();
        }
        else{
            control->setCommand(sendllamada);
            control->buttonPressed();
        }
    }

    delete usuario, sendE, sendsms, sendllamada, control;

    return 0; 
}