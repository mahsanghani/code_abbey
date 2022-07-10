//
// Created by Ahsan Ghani on 2022-07-09.
//

// Singleton is a creational design pattern that
// lets you ensure that a class has only one instance,
// while providing a global access point to this instance.

#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <thread>
#include <unordered_map>
using namespace std;

class Singleton {
protected:
    Singleton(const string value): value_(value) {}

    static Singleton* singleton_;
    string value_;

public:
    Singleton(Singleton &other) = delete;
    void operator = (const Singleton &) = delete;

    static Singleton *GetInstance(const string value);
    void SomeBusinessLogic() {}
    string value() const
    {
        return value_;
    }
};

Singleton* Singleton::singleton_ = nullptr;

Singleton *Singleton::GetInstance(const string value)
{
    if(singleton_== nullptr)
    {
        singleton_ = new Singleton(value);
    }
    return singleton_;
}

void ThreadFoo()
{
    this_thread::sleep_for(chrono::milliseconds(1000));
    Singleton* singleton = Singleton::GetInstance("FOO");
    cout << singleton->value() << endl;
}

void ThreadBar()
{
    this_thread::sleep_for(chrono::milliseconds(1000));
    Singleton* singleton = Singleton::GetInstance("BAR");
    cout << singleton->value() << endl;
}

int main()
{
    cout << "If you see the same value" << endl;
    cout << "then the singleton was reused." << endl;
    cout << "If you see a different value" << endl;
    cout << "then 2 singletons were created." << endl;
    thread t1(ThreadFoo);
    thread t2(ThreadBar);
    t1.join();
    t2.join();

    return 0;
}
