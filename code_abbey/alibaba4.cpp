//
// Created by Ahsan Ghani on 2020-09-14.
//

#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main(void){
    string s;
    map<string,int> counts;
    vector<string> duplicates;
    cout << "input data:" << endl;
    do{
        cin >> s;
        counts[s]++;
    }while(s.compare("end") != 0);
    for(auto i=counts.cbegin(); i != counts.cend(); i++){
        if(i -> second > 1){
            duplicates.push_back(i->first);
        }
    }
    sort(duplicates.begin(),duplicates.end());
    for(int j=0;j<duplicates.size();j++){
        cout << duplicates[j] << " ";
    }
    return 0;
}