#include <iostream>
#define tam 100
using namespace std;

int f(int a[],int tamA,int b[],int& tamB)
{
    int diferentes=0,i;

    for(i=0; i<tamA; i++)
    {
        if(i==0)
            b[i]=a[i];
        else
            for(int j=tamA-1; j>=0; j--)
            {
                if(a[i]==a[j])
                    continue;
                else
                {
                    b[i]=a[i];
                    diferentes++;
                }
            }
    }
    b[i]=0;

    tamB=diferentes;

    return diferentes;
}

int main()
{

    int v1[tam],v2[tam],tamv1,tamv2=0,i; //tamv2 tá iniciada em zero porque o vetor está vazio

    cout<<"Tamanho do primeiro vetor:";
    cin>>tamv1;

    cout<<"Elementos do primeiro vetor:";
    for(i=0; i<tamv1; i++)
        cin>>v1[i];

    cout<<"Elementos do novo vetor:"<<endl;
    for(i=0; i<tamv2; i++)
        cout<<v2[i]<<endl;

    cout<<"Quantidade de Elementos que são diferentes no primeiro vetor:"<<f(v1,tamv1,v2,tamv2);

    return 0;
}
