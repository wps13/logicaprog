//indentifica o menor elemento do vetor

#include <iostream>
using namespace std;
#define tam 30

int main()
{
    int v1[tam];
    int n;
    int menor=100000;

    cout<<"Digite a quantidade de elementos do vetor:";
    cin>>n;

    cout<<"Digite os elementos do vetor:";
    for(int i=0; i<n; i++)
    {
        cin>>v1[i];
        if(menor>v1[i])
        menor=v1[i];

    }
    cout<<menor;
}

