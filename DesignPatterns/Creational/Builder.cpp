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

