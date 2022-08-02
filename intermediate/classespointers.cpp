//
// Created by Ahsan Ghani on 2022-08-01.
//
#include <iostream>
using namespace std;

class Dog
{
public:
    Dog() = default;
    Dog(string_view name_param, string_view breed_param, int age_param);
    ~Dog();

    void print_info()
    {
        cout << "Dog (" << this << ") : [ name : " << name
             << " bread : " << breed << " age : " << *p_age << "]" << endl;
    }

//     Setters
//     Chained calls using pointers
//    Dog* set_dog_name(string_view name)
//    {
//        // name = name;
//        this->name = name;
//        return this;
//    }
//    Dog* set_dog_breed(string_view breed)
//    {
//        this->bread = breed;
//        return this;
//    }
//    Dog* set_dog_age(int age)
//    {
//        *(this->p_age) = age;
//        return this;
//    }

//     Chained calls using references
    Dog& set_dog_name(string_view name)
    {
        // name = name;
        this->name = name;
        return *this;
    }
    Dog& set_dog_breed(string_view breed)
    {
        this->breed = breed;
        return *this;
    }
    Dog& set_dog_age(int age)
    {
        *(this->p_age)() = age;
        return *this;
    }

private:
    string name;
    string breed;
    int * p_age(nullptr);
};

Dog::Dog(string_view name_param, string_view breed_param, int age_param)
{
    name = name_param;
    breed = breed_param;
    p_age = new int;
    *p_age = age_param;
    cout << "Dog constructor called for " << name << " at " << this << endl;
}

Dog::~Dog()
{
    delete p_age;
    cout << "Dog destructor called for " << name << " at " << this << endl;
}

int *Dog::p_age() {
    return nullptr;
}

int main()
{
    Dog dog1("Fluffy", "Shepherd", 2);
    dog1.print_info();

//    dog1.set_dog_age(4);
//    dog1.set_dog_name("Pumba");
//    dog1.set_dog_breed("Wire Fox Terrier");

//    Chained calls using pointers
//    dog1.set_dog_age(4)->set_dog_name("Pumba")->set_dog_breed("Wire Forx Terrier");

//    Chained calls using references
    dog1.set_dog_age(4).set_dog_name("Pumba").set_dog_breed("Wire Fox Terrier");

    dog1.print_info();

    cout << "Done!" << endl;

    return 0;
}