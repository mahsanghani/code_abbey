//
// Created by Ahsan Ghani on 2022-08-26.
//
#ifndef ENGINEER_H
#define ENGINEER_H
#include "person.h"

//Engineer is doing private inheritance

class Engineer : public Person
{
    friend std::ostream& operator<<(std::ostream& out , const Engineer& operand);
public:
    Engineer();
    ~Engineer();

    void build_something(){
        m_full_name = "John Snow"; // OK
        m_age = 23; // OK
        //m_address = "897-78-723"; Compiler error
    }

    int get_contract_count() const{
        return contract_count;
    }

private :
    int contract_count{0};
};

#endif // ENGINEER_H