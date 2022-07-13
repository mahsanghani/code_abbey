//
// Created by Ahsan Ghani on 2022-07-13.
//

// Proxy is a structural design pattern that
// provides an object that acts as a substitute
// for a real service object used by a client.
// A proxy receives client requests,
// does some work (access control, caching, etc.)
// and then passes the request to a service object.

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Subject
{
public:
    virtual void Request() const = 0;
};

class RealSubject : public Subject
{
public:
    void Request() const override
    {
        cout << "RealSubject: Handling request." << endl;
    }
};

class Proxy : public Subject
{
private:
    RealSubject *real_subject_;
    bool CheckAccess() const
    {
        cout << "Proxy: Checking access prior to firing a real request." << endl;
        return true;
    }
    void LogAccess() const
    {
        cout << "Proxy: Logging the time of request." << endl;
    }

public:
    Proxy(RealSubject *real_subject) : real_subject_(new RealSubject(*real_subject)) {}
    ~Proxy()
    {
        delete real_subject_;
    }

    void Request() const override
    {
        if(this->CheckAccess())
        {
            this->real_subject_->Request();
            this->LogAccess();
        }
    }
};

void ClientCode(const Subject &subject)
{
    subject.Request();
}

int main()
{
    cout << "Client: Executing the client code with a real subject: \n";
    RealSubject *real_subject = new RealSubject;
    ClientCode(*real_subject);
    cout << "\n Client: Executing the same client code with a proxy: \n";
    Proxy *proxy = new Proxy(real_subject);
    ClientCode(*proxy);

    delete real_subject;
    delete proxy;
    return 0;
}
