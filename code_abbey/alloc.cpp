#include <iostream>   
#include <cstdlib> 
#include <string>
 
int main() 
{
    // allocates enough for an array of 4 strings
    if(auto p = (std::string*)std::malloc(4 * sizeof(std::string)))
    {
        int i = 0;
        try
        {
            for(; i != 4; ++i) // populate the array
                new(p + i) std::string(5, 'a' + i);
 
            for(int j = 0; j != 4; ++j) // print it back out
                std::cout << "p[" << j << "] == " << p[j] << '\n';
        }
        catch(...) {}
 
        for(; i != 0; --i) // clean up
            p[i - 1].~basic_string();
 
        std::free(p);
    }
}