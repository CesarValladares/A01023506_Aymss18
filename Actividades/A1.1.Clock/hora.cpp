#include <iostream>
#include <stdio.h>
#include <ctime>

using namespace std;

class Clock
{
private:
    
    static Clock* instance;

    Clock()
    {
        cout << "Constructor" << endl; 
    }

    delete();
public: 
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

    cout << "instance 1: " << instance1 << endl; 
    cout << "instance 2: " << instance2 << endl; 


    return 0;
}