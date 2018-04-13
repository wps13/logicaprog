#include <iostream>

using namespace std;

int main()
{
    int i;
    int vet1[4];
    int vet2[4];
    int vet3[4];

    cout<<"Digite 4 valores para o primeiro vetor:";
    cin>>vet1[0]>>vet1[1]>>vet1[2]>>vet1[3];
    cout<<"Digite 4 valores para o segundo vetor:";
    cin>>vet2[0]>>vet2[1]>>vet2[2]>>vet2[3];

    cout<<"Terceiro vetor:"<<endl;
    for(i=0; i<4; i++)
    {
        vet3[i]=vet1[i]+vet2[i];
        cout<<vet3[i]<<endl;
    }


}
