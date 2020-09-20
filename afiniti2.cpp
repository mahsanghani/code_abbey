//
// Created by Ahsan Ghani on 2020-09-17.
//

#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int input[] = {5, 2, 6, 0, 3, 0, 11, 0, 11};
    int size = sizeof(input)/sizeof(input[0]);
    // size of array

    int i=0;
    // if element at index j is a non-zero
    // replace element at index i with element at index j
    for(int j=0;j<size;j++){
        if(input[j] != 0){
            input[i++]=input[j];
        }
    }
    // make all elements 0 from i to end of size
    while(i<size){
        input[i++]=0;
    }
    // loop to print
    for (int k = 0;k<size;k++){
        cout << input[k] << " ";
    }
    return 0;
}