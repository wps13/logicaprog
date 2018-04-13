//testa se um número é ou não perfeito

#include <iostream>
using namespace std;

bool perfeito(int x);

int main()
{
    int num;

    cout<<"Digite um número:";
    cin>>num;

    if(perfeito(num)==true)
        cout<<"O número é perfeito.";
    else
        cout<<"O número não é perfeito.";

    return 0;
}

bool perfeito(int x)
{

    int divisores=0;

    if(x<0)
        x*=(-1);

    for(int i=1; i<x; i++)
    {
        if(x%i==0)
            divisores+=i;
    }
    if(divisores==x)
        return true;
    else
        return false;
}
