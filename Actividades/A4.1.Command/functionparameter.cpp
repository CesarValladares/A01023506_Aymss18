#include <iostream>
#include <string>

using namespace std;

//DEVUELVE ENTEROS RECIBIENDO  FUNCIONES

int suma (int a, int b){
    return a+b;
}

int resta (int a, int b){
    return a-b;
}

int duplica(int a)
{
    return 2 * a;
}

int operacion (int a, int b, int (*f)(int, int))
{
    return f(a,b);
}

//DEVUELVE FUNCIONES 
typedef int (*f)(int, int);

//opcion 1
f getOperacion(char o)
{
    if (o == 'r') {
        return resta;
    }
    else
    {return suma;}
}

//opcion 2
int (*getF(char s))(int a, int b){
    if (s == 'r') {
        return resta;
    }
    else
    {return suma;}
}

//CON TAMPLATES

template <class T, class Function>
T doTemplateFunction(T a, T b, Function f){
    return f(a,b);
}

template<class Function2>
Function2 getTemplateOperation(char s)
{
    if (s == 's') {
        return suma;
    }
    else if (s == 'r')
    {return resta;}
    /*else if (s == 'd')
    {return duplica;}*/
}

int main (){
    //opcion 1
    //cout << operacion(2,2,suma) << endl;
    //cout << operacion(5,2,resta) << endl; 

    //opcion 2
    //cout << getF('s')(2,2) << endl; 

    //Template
    cout << doTemplateFunction(2,2,suma) << endl;

    cout << getTemplateOperation<int (*)(int,int)>('s')(2,2) << endl;

    return 0;

}