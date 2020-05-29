//
// Created by Ahsan Ghani on 2020-05-27.
//

#include <iostream>
#include <string>
int const MAX=1000;

using namespace std;

void is_A_max(int A[])
{
    for (int i=0; i<MAX; i++)
    {
        A[i]=0;
    }
}

void mod_A(unsigned x, int A[])
{
    int i=0;
    is_A_max(A);
    while(x)
    {
        A[i++] = x%10;
        x /= 10;
    }
}

int mod_sum(int A[], int B[], int C[])
{
    int sum;
    int p=0;
    for(int i=0;i<MAX;i++)
    {
        sum=A[i]+B[i]+p;
        C[i]=sum%10;
        p = sum/10;
    }
    return p;
}

void AisB(int A[], int B[])
{
    for(int i=0;i<MAX;i++)
    {
        A[i]=B[i];
    }
}

bool compare(int A[], int B[]);
int fib(int A[], int B[], int C[], int D[]);

int main()
{
    int a, i, qty=0;
    int count=0;
    int A[MAX]{0};
    int B[MAX]{0};
    int C[MAX]{0};
    int D[MAX]{0};

    cin>>qty;
    cin.get();
    string line;
    A[0]=0;
    B[0]=1;
    for(i=0;i<qty;i++)
    {
        getline(cin,line);
        a=line.size();
        while(a>0)
        {
            D[count]=(int)line[a-1]-48;
            count++;
            a--;
        }
        a=line.size();
        cout<<fib(A,B,C,D)<<" ";
        is_A_max(D);
        is_A_max(A);
        is_A_max(B);
        is_A_max(C);
        A[0]=0;
        B[0]=1;
        count=0;
    }
    return 0;
}

bool compare(int A[], int B[])
{
    for(int i=0;i<MAX;i++)
    {
        if(A[i]!=B[i])
        {
            return true;
        }
    }
    return false;
}

int fib(int A[], int B[], int C[], int D[])
{
    int count=0;
    if(!compare(C,D))
    {
        return 0;
    }
    while(compare(C,D))
    {
        mod_sum(A,B,C);
        AisB(A,B);
        AisB(B,C);
        count++;
    }
    return count+1;
}