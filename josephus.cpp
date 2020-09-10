//
// Created by Ahsan Ghani on 2020-06-03.
//

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

vector<vector<int>> input(int& a, int& b, int& qty)
{
    vector<int> one_set;
    vector<vector<int>> all_sets;

    cout << "input data:" << endl;
    cin >> qty;
    for (int i = 0; i < qty; i++)
    {
        cin >> a >> b;
        one_set.push_back(a);
        one_set.push_back(b);

        all_sets.push_back(one_set);

        one_set.clear();
    }

    return all_sets;
}

vector<int> process(vector<vector<int>>data)
{
    vector<int> survivors;
    vector<int> temp_vec;

    for (int i=0;i<data.size();i++)
    {   int skips = data[i][1];
        int start = skips;
        for(int j=0;j<data[i][0];j++)
        {
            temp_vec.push_back(j);
        }
        while(temp_vec.size()>1)
        {
            for(int k=start;k<temp_vec.size();k += skips)
            {
                temp_vec.erase(temp_vec.begin()+k);
                if((k>temp_vec.size()-skips) || (k=temp_vec.size()-skips))
                {
                    start = skips - (temp_vec.size()-k);
                }
            }
        }
        survivors.push_back(temp_vec[i]);
    }
    return survivors;
}

void output(vector<int> survivors)
{
    cout << "answer: " << endl;
    for (int i = 0; i < survivors.size(); i++)
    {
        cout << survivors[i] << " ";
    }
}

int main(void)
{
    int a, b, qty;
    auto data = input(a, b, qty);
    auto result = process(data);
    output(result);

    return 0;
}

*def solveJosephus(specifics):
    people = [int(x) for x in range(1,int(specifics[0])+1)]
    killPosition = int(specifics[1])
    positionCounter = 0
    sorted = False

    while not sorted:
        if len(people) == 1:
            print(people[0]) # Pyschologically scarred Winner!
            sorted = True
        for person in people[:]: #Make copy of iterating list
            positionCounter += 1
            if positionCounter == killPosition:
                people.remove(person)
                positionCounter = 0

solveJosephus(raw_input().split())*/`