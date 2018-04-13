#include <iostream>

using namespace std;

int main()
{
    char nome[21];
    int cont;

    cont=-1;
    cout<<"Digite o nome:";
    cin.getline(nome,20);

    for(int i=0; nome[i]!='\0'; i++)
    {
        cont++ ;
    }
    cout<<cont;
}
