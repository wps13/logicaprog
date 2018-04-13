#include <iostream>
#define tam 100
using namespace std;

int menor(int v1[],int n);

int main()
{
    int v[tam],tamV;

    cout<<"Tamanho do vetor:";
    cin>>tamV;

    cout<<"Elementos do vetor:"<<endl;
    for(int i=0; i<tamV; i++)
        cin>>v[i];

    cout<<"Índice do menor elemento no vetor:"<<menor(v,tamV);

    return 0;
}

int menor(int v1[],int n)
{
    int menor=v1[0],pos=0;
    for(int i=0; i<n; i++)
    {
        if(v1[i]<menor)
        {
            menor=v1[i];
            pos=i;
        }
    }
    return pos;
}
