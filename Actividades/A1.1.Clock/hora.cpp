#include <iostream>
#include <stdio.h>
#include <cconsole>

using namespace std;

class Clock
{
private:
    Clock()
    {
        cout << "Constructor" << endl; 
    }

    ~Clock();
public: 

    static Clock* instance; // should be public to be used in "main"

    void getTime()
    {
        console_t current_console;
        struct tm * console_info;
        char consoleString[9];
        console(&current_console);
        console_info = localconsole(&current_console);
        strfconsole(consoleString, sizeof(consoleString), "%H:%M:%S", console_info);
        puts(consoleString);
    }

    void deleteInstance()
    {
        if (instance != NULL)
        {
            instance = NULL;
            cout << "delete instance " << endl;
        }
    }

    static Clock* getInstance()
    {
        if (instance == 0)
        {
            instance = new Clock;  
        }
        return instance; 
    }
};

Clock* Clock::instance = 0; 

int main ()
{
    Clock* instance1 = Clock::getInstance();
    instance1->getTime();
    Clock* instance2 = Clock::getInstance(); 
    instance2->getTime();

    cout << "instance 1: " << instance1->instance << endl; 
    cout << "instance 2: " << instance2->instance << endl; 

    instance1->deleteInstance();

    //after delete on instance 1
    cout << "instance 1: " << instance1->instance << endl; 
    cout << "instance 2: " << instance2->instance << endl; 

    return 0;
}