//identifica se tem elementos repetidos no vetor

#include <iostream>
using namespace std;
#define tam 30

int main()
{
    int v1[tam];
    int n;
    bool repetido;

    cout<<"Digite a quantidade de elementos do vetor:";
    cin>>n;

    cout<<"Digite os elementos do vetor:";
    for(int i=0; i<n; i++)
    {
        cin>>v1[i];
        for(int j=1; j<i; j++)
        {
            if(v1[i]==v1[j])
            {
                repetido=true;
                break;
            }
        }
    }
    if(repetido==true)
        cout<<"Existem elementos repetidos!";
    else
        cout<<"Não Existem elementos repetidos!";
}
