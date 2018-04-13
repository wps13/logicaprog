#include <iostream>
#define tam 100
using namespace std;

bool procura(int v[],int tamV,int x)
{
    int cont=0;
    for(int i=0; i<tamV; i++)
    {
        if(v[i]==x)//testa se o valor da posiçao é igual ao num
            cont++;
    }
    if(cont!=0)
        return true;
    else
        return false;
}
void compara(int v1[],int v2[],int tamv1,int tamv2)
{
    int i,j;
    for(i=0; i<tamv1; i++)
    {
        for(j=0; j<tamv2; j++)
        {
            if(v1[i]==v2[j])
                cout<<v1[i]<<endl;
        }
    }
}
int main(){
    int vetor1[tam],vetor2[tam],n,m,i,v[tam],tv,elem;

    cout<<"Digite o tamanho do primeiro vetor:";
    cin>>n;
    cout<<"Digite os elementos do vetor:";
    for(i=0;i<n;i++)
    cin>>vetor1[i];

cout<<"Digite o tamanho do primeiro vetor:";
    cin>>m;
    cout<<"Digite os elementos do vetor:";
    for(i=0;i<m;i++)
    cin>>vetor2[i];

    compara(vetor1,vetor2,n,m);

    cout<<"Digite um elemento para buscar no vetor :";
    cin>>elem;
    cout<<"Digite o tamanho do vetor para busca:";
    cin>>tv;
    cout<<"Digite os elementos do vetor:";
    for(i=0;i<tv;i++)
    cin>>v[i];

    if(procura(v,tv,elem)==true)
    cout<<"O elemento encontra-se no vetor";
    else
    cout<<"O elemento não encontra-se no vetor";
}
