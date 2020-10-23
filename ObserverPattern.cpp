// ObserverPattern.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

class IObserver
{
public:
    virtual void Update() = 0;
};

class IEvent
{
    virtual int Add(IObserver* i) = 0;
    virtual int Remove(IObserver* i) = 0;
    virtual void Notifiy() = 0;
};

class ProgramEvents : public IEvent
{
private:
    std::vector<IObserver *> _Observers;

public:
    int Add(IObserver* i);
    int Remove(IObserver* i);
    void Notify();
};


int main()
{
    std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file


/***************************************************

               Class definitions Below


****************************************************/

int ProgramEvents::Add(IObserver * i)
{
    _Observers.push_back(i);

    return _Observers.size();
}

int ProgramEvents::Remove(IObserver* i)
{
   // _Objservers.remove(); TODO
    return _Observers.size();
}

void ProgramEvents::Notify()
{
    std::vector<IObserver*>::iterator _start;
    ;
    for (_start = _Observers.begin(); _start != _Observers.end(); _start++)
    {
        (*_start)->Update();
    }
}