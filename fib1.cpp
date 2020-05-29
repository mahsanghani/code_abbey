//
// Created by Ahsan Ghani on 2020-05-27.
//

#include <iostream>
#include <string>
int const MAX_TAB{1000};

void vliZeruj(int A[])
{
    for(int i{0};i<MAX_TAB;i++)
    {
        A[i]=0;
    }
}

void vliInt2Vli(unsigned x,int A[])
{
    int i{0};
    vliZeruj(A);
    while(x)
    {
        A[i++]=x%10;
        x /=10;
    }

}
int vliDodaj(int A[],int B[],int C[])
{
    int i,p{0},su;
    for(int i=0;i<MAX_TAB;i++)
    {
        su=A[i]+B[i]+p;
        C[i]=su%10;
        p=su/10;
    }
    return (p);
}
void vliPrzepisz(int A[],int B[])
{
    for(int i=0;i<MAX_TAB;i++)
    {
        A[i]=B[i];
    }
}
int fib(int A[],int B[],int C[],int D[]);
bool compare(int A[],int B[]);

int main()
{
    int A[MAX_TAB]{0},B[MAX_TAB]{0},C[MAX_TAB]{0},D[MAX_TAB]{0};
    int howMuchNumbers{0},counter{0};

    std::cin>>howMuchNumbers;
    std::cin.get();
    std::string line;
    A[0]=0;
    B[0]=1;
    int a;
    for(int i = 0;i<howMuchNumbers;i++)
    {

        std::getline(std::cin,line);
        a=line.size();
        while(a>0)
        {
            D[counter]=(int)line[a-1]-48;
            counter++;
            a--;
        }
        a=line.size();
        std::cout<<fib(A,B,C,D)<<std::endl;
        vliZeruj(D);
        vliZeruj(A);
        vliZeruj(B);
        vliZeruj(C);
        A[0]=0;
        B[0]=1;
        counter=0;

    }
    return 0;
}
int fib(int A[],int B[],int C[],int D[])
{
    int counter{0};
    if(!compare(C,D))
        return 0;
    std::cout<<counter<<" ";
    while(compare(C,D))
    {
        vliDodaj(A,B,C);
        vliPrzepisz(A,B);
        vliPrzepisz(B,C);
        counter++;
    }
    std::cout<<counter+1<<" ";
    return counter+1;
}
bool compare(int A[],int B[])
{
    for(int i=0;i<MAX_TAB;i++)
    {
        if(A[i]!=B[i])
            return true;
    }
    return false;
}