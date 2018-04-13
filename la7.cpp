//soma os elementos de um vetor

#include <iostream>
using namespace std;
#define tam 30

int main()
{
    int v1[tam];
    int n;
    int soma=0;

    cout<<"Digite a quantidade de elementos do vetor:";
    cin>>n;

    cout<<"Digite os elementos do vetor:";
    for(int i=0; i<n; i++)
    {
        cin>>v1[i];
        soma+=v1[i];

    }
    cout<<soma;
}
