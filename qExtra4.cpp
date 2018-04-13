//o programa testa se existe algum elemento repetido no vetor
#include <iostream>
#define tam 100
using namespace std;

bool repete(int v[],int n)
{
    int num=0,i,j;
    for(i=0; i<n; i++) //testa uma posição com as demais,tipo a primeira com o resto,segunda com resto
    {
        for(j=0; j<i; j++)//vale a linha para depois alterar a posição que está se comparando
        {
            if(v[i]==v[j])
                num++;
        }
    }
    if(num!=0)
        return true;
    else
        return false;
}

int main()
{
    int vetor[tam],tamV;

    cout<<"Digite o tamanho do vetor:";
    cin>>tamV;

    for(int i=0; i<tamV; i++)
        cin>>vetor[i];
    if(repete(vetor,tamV)==true)
        cout<<"true";
    else
        cout<<"false";

}
