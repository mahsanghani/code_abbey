//
// Created by Ahsan Ghani on 2022-07-07.
//

// Builder is a creational design pattern that
// lets you construct complex objects step by step.
// The pattern allows you to produce different types and
// representations of an object using the same construction code.

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Product1{
public:
    std::vector<std::string> parts_;
    void ListParts()const{
        std::cout << "Product parts: ";
        for (size_t i=0;i<parts_.size();i++){
            if(parts_[i]==parts_.back()){
                std::cout << parts_[i];
            }else{
                std::cout << parts_[i] << ", ";
            }
        }
        std::cout << "\n\n";
    }
};

class Builder{
public:
    virtual ~Builder(){}
    virtual void ProducePartA() const = 0;
    virtual void ProducePartB() const = 0;
    virtual void ProducePartC() const = 0;
};

class ConcreteBuilder1 : public Builder {
private:
    Product1* product;

public:
    ConcreteBuilder1(){
        this->Reset();
    }

    ~ConcreteBuilder1(){
        delete product;
    }

    void Reset(){
        this->product = new Product1();
    }

    void ProducePartA()const override{
        this->product->parts_.push_back("PartA1");
    }

    void ProducePartB()const override{
        this->product->parts_.push_back("PartB1");
    }

    void ProducePartC()const override{
        this->product->parts_.push_back("PartC1");
    }

    Product1* GetProduct() {
        Product1* result = this->product;
        this->Reset();
        return result;
    }
};

