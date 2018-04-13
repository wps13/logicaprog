#include <iostream>
using namespace std;
int main()
{
    int tam,produto,somaMedia=0,media,i,j,cont=0,contDivisor=0;
    int vet[tam];

    cout<<"Digite o tamanho do vetor(maior ou igual a 3):";
    cin>>tam;

    for(i=0; i<tam; i++)
    {
        cout<<"Digite as componentes do vetor:";
        cin>>j;
        vet[i]=j;
    }
    produto=vet[0]+vet[tam/2]+vet[tam-1];
    for(i=tam/2-1; i>=0; i--)
    {
        somaMedia=somaMedia+vet[i];
        cont++;
    }
    media=somaMedia/cont;
    for(i=tam/2+1; i<tam; i++)
    {
        if(vet[i]%5==0 && vet[i]!=0)
            contDivisor++;
    }
    cout<<"Produto:"<<produto<<endl;
    cout<<"Média:"<<media<<endl;
    cout<<"Números divisiveis por 5 e não por 2:"<<contDivisor;
}
