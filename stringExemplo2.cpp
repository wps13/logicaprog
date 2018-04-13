//testar se a cadeia é um número inteiro

#include <iostream>
#include <ctype.h>
#define tam 20
using namespace std;

int main()
{
    int sn[tam];
    int n,i;
    bool carac=true;

    cout<<"Tamanho:";
    cin>>n;

    cout<<"Digite a cadeia:";

    for(i=0; i<n; i++)
    {
        cin>>sn[i];
        if(isdigit(sn[i])==false)
        {
            carac=false;
        }
    }
    sn[i]=0;
    if(carac)
        cout<<"é um número";
    else
        cout<<"Não é um número";
}
