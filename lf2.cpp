//calcula o fatorial de um número
#include <iostream>
using namespace std;

long int fatorial(int n)
{
    int soma=1;
    for(int i=1; i<=n; i++)
        soma*=i;

    return soma;
}

int main()
{
    int num;

    do
    {
        cout<<"Digite um número:";
        cin>>num;
    }
    while(num<=0);

    cout<<"Fatorial de "<<num<<" = "<< fatorial(num);

    return 0;
}
