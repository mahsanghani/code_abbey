//
// Created by Ahsan Ghani on 2020-08-12.
//

#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int cases;
    cin >> cases;
    cin.clear();
    cin.ignore();
    for (int i = 0; i < cases+1; i++)
    {
        vector<char> open;
        vector<char> close;
        char op, cl;
        bool correct = true;
        char line[128];
        cin.getline(line, 128);
        int c = 0;

        do
        {
            char symb;
            symb = line[c];
            if (symb == '\0') break;
            c++;

            switch (symb)
            {
                case('('): case('['): case('{'): case('<'):
                    open.push_back(symb);
                    break;

                case(')'): case(']'): case('}'): case('>'):
                    close.push_back(symb);
                    if (open.empty()) {correct = false;}
                    else
                    {
                        op = open.back();
                        cl = close.back();
                    }

                    if ((op == '(') && (cl != ')') || (op == '[') && (cl != ']') ||
                        (op == '{' && cl != '}') || (op == '<' && cl != '>')) correct = false;
                    else open.pop_back(), close.pop_back();
                    break;

                default:
                    break;
            }
        } while (correct);

        if(!open.empty() && close.empty()) correct = false;
        std::cout << correct << " ";
    }
    return 0;
}