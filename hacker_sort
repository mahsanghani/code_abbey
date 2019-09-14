#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <ostream>
#include <algorithm>
using namespace std;


int main() {
    int qty;
    cin >> qty;
    vector<int> my_vector(qty);  
    for(int i=0;i<qty;i++)
    {
        cin >> my_vector[i];
        /*int j;
        cin >> j;
        my_vector.push_back(j);*/
    }

    int temp,min,max;
    cin >> temp >> min >> max;
    if(temp<my_vector.size())
    {
    my_vector.erase(my_vector.begin()+temp-1);
    }
    if(min < max && max < my_vector.size()){
    my_vector.erase(my_vector.begin()+min-1,my_vector.end()+max-1);
    }

    cout << my_vector.size() << endl;
    //copy(begin(my_vector), end(my_vector), ostream_iterator<int>(cout, " "));
    for(int i=0;i<my_vector.size();i++)
    {
        cout << my_vector[i] << " ";
    }
    cout << endl;
    return 0;
}
