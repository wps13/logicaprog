#include <iostream>

using namespace std;

int main()
{
    char palavra[100];
    char inversa[100];
    int cont;

    cout<<"Digite uma palavra:";
    cin.getline(palavra,99);
    cont=-1;
    for(int i=0; palavra[i]!='\0'; i++)
    {
        cont++ ;
    }

    for(int i=cont,j=0; i>=0; i--,j++)
    {
        inversa[j]=palavra[i];
    }
    inversa[cont+1]='\0';
    cout<<inversa;
}
