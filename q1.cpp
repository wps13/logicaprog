//verifica se o número é ou não perfeito
#include <iostream>
using namespace std;

int perf(int x)//recebe o número
{
    int soma=0;
    for(int i=1; i<x; i++)
    {
        if(x%i==0)//testa se o número é divisor e se for,adiciona a soma
            soma+=i;
    }

    return soma;
}

int main()
{
    int n;
    cout<<"Digite um número inteiro positivo:";
    cin>>n;


    if(perf(n)==n)
        cout<<"O número é um número perfeito.";
    else
        cout<<"O número não é um número perfeito";

    return 0;
}
