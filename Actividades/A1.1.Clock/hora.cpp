#include <iostream>
#include <stdio.h>
#include <ctime>

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
        time_t current_time;
        struct tm * time_info;
        char timeString[9];
        time(&current_time);
        time_info = localtime(&current_time);
        strftime(timeString, sizeof(timeString), "%H:%M:%S", time_info);
        puts(timeString);
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