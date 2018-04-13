//testa se o caractere é maiúsculo ou minusculo
#include <iostream>
using namespace std;

bool caractere(char x)
{
    int t=x;

    if((t>=65) && (t<=90))
        return true;
    else //if((t>=97) || (t<=122))
        return false;
}

int main()
{
    char c;

    cout<<"Digite um caractere:";
    cin>>c;


    if(caractere(c)==true)
        cout<<"O caractere é maiúsculo.";
    else
        cout<<"O caractere não é maiúsculo.";

}
