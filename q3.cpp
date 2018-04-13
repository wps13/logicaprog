//mostrar divisores de um número
#include <iostream>
using namespace std;

int divisores(int x)
{
    for(int i=1; i<=x; i++)
    {
        if(x%i==0)
            cout<<'\t'<<i;
    }
}

int main()
{
    int n;

    cout<<"Digite um número:";
    cin>>n;

    divisores(n);
    return 0;
}
