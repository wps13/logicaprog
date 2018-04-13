#include <iostream>
#define tam 100
using namespace std;

void comb(int v[],int n,int k)
{
    int vtemp[tam],i,j=0;
    for(i=0; i<n; i++)
    {
        if(j<k && (k>n||v[j]<=v[k]))
        {
            vtemp[i]=v[j];
            j++;
        }
        else
        {
            vtemp[i]=v[k];
            k++;

        }
        for(i=0; i<n; i++)
        {
            v[i]=vtemp[i];

        }
    }
    }
    int main()
    {
        int tamv,v[tam],pos;

        cout<<"Posição desejada:";
        cin>>pos;
        cout<<"Tamanho do vetor:";
        cin>>tamv;

        cout<<"Vetor:";
        for(int i=0; i<tamv; i++)
            cin>>v[i];

        comb(v,tamv,pos);

    }
