//
// Created by Ahsan Ghani on 2022-07-31.
//
#include <iostream>
#include <concepts>
using namespace std;
//This syntax constrains the auto parameters you pass in
//to comply with the std::integral concept
std::integral auto add (std::integral auto a,std::integral auto b){
    return a + b;
}
int main(){
    auto x = add(5,8);
    cout << x << endl;
    return 0;
}