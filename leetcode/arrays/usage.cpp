#include <iostream>

int main()
{
    int a[5];
    int b[5] = {1,2,3};
    int size = sizeof(a) / sizeof(*a);
    cout << "The size of a is: " << size << endl;
    cout << "The first element is: " << b[0] << endl;
    cout << "[version 1] The contents of b are:";
    for (int i=0; i<size; ++i){
        cout << " " << b[i];
    }
    cout << endl;
    cout << "[version 2] The contents of b are:";
    for (int& item: b){
        cout << " " << item;
    }
    cout << endl;
    b[0]=4;
    sort(a,a+size);
}
