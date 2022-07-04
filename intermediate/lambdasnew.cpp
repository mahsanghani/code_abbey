//
// Created by Ahsan Ghani on 2022-07-04.
//
#include <iostream>

int main(){
    /*
    Lambda function signature :
    [capture list] (parameters) ->return type{
            // Function body
    }
    */

    //Declaring a lambda function and calling it through a name

    auto func = [](){
        std::cout << "Hello World!" << std::endl;
    };
    func();
    func();

    //Declare a lambda function and call it directly
    [](){
        std::cout << "Hello World!" << std::endl;
    }();

    //Lambda function that takes parameters
    [](double a, double b){
        std::cout << "a + b : " << (a + b)  << std::endl;
    }(10.0,50.0);


    auto func1 = [](double a, double b){
        std::cout << "a + b : " << (a + b)  << std::endl;
    };
    func1(10,20);
    func1(5,7);

    //Lambda function that returns something

    auto result = [](double a, double b){
        return a + b;
    }(10,60);
    //std::cout << "result : " << result << std::endl;
    std::cout << "result : " << [](double a, double b){
        return a + b;
    }(10,60) << std::endl;

    auto func2 = [](double a, double b){
        return a + b;
    };
    auto result3 = func2(23,7);
    auto result4 = func2(9,45);
    std::cout << "result3 : " << result3 << std::endl;
    std::cout << "result4 : " << result4 << std::endl;
    std::cout  <<"direct call : " << func2(5,2) << std::endl;

    //Explicitly specify the return type
    auto func3 = [](double a, double b)-> int{
        return a + b;
    };

    auto func4 = [](double a, double b){
        return a + b;
    };

    double a{6.9};
    double b{3.5};

    auto result5 = func3(a,b);
    auto result6 = func4(a,b);

    std::cout << "result5 : " << result5 << std::endl;
    std::cout << "result6 : " << result6 << std::endl;
    std::cout << "sizeof(result5) : " << sizeof(result5) << std::endl; // 4
    std::cout << "sizeof(result6) : " << sizeof(result6) << std::endl; // 8

    std::cout << "Done!" << std::endl;

    return 0;
}