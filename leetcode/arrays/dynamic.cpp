#include <iostream>

int main(){
    vector<int> a;
    vector<int> b(5,0);
    vector<int> c(b.begin(), b.end());
    vector<int> d(c);
    
    int z[5] = {0,1,2,3,4};
    vector<int> e(z, *(&z + 1));
    
    cout << "The size of e is: " << e.size() << endl;
    cout << "The first element of e is: " << e[0] << endl;
    cout << "[version 1] The contents of e are: " ;
    
    for(int i=0; i<e.size(); ++i){
        cout << " " << e[i];
    }
    
    cout << endl;
    cout << "[version 2] The contents of e are: " ;
    for (int& item : e){
        cout << " " << item;
    }
    cout << endl;
    cout << "[version 3] The contents of e are: " ;
    for (auto item = e.begin(); item != e.end(); ++item){
        cout << " " << *item;
    }
    
    cout << endl;
    e[0] = 5;
    sort(e.begin(), e.end());
    e.push_back(-1);
    e.pop_back();
}
