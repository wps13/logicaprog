#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int num,i;
    int vetor[10];
    cout<<"Digite um número entre -7 e 7:";
    cin>>num;

    for(i=0; i<10; i++){
        vetor[i]=pow(i,num);
        cout<<vetor[i]<<endl;
}
}
