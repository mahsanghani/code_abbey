//
// Created by Ahsan Ghani on 2020-09-10.
//

#include <iostream>
#include <vector>

using namespace std;

int main(void){

    int num;
    cin >> num;

    // check integer
    // check limits
    if(int(num) != num || num<=1 || num>=2147483647){
        return 0;
    }
    // convert binary
    int binaryNum[32];
    int i=0;
    while(num>0){
        binaryNum[i]=num%2;
        num /= 2;i++;
    }
    int max_count=0;int counter=0;
    for(int j=0;j<32;j++){
        if (binaryNum[j]==1){
            j++;
            if(binaryNum[j]==0){
                counter++;
                if(binaryNum[j+1]==1 && counter>max_count){
                    max_count=counter;
                }else{counter=0;}
            }
        }
    }


    return 0;
}