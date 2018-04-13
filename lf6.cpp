//testa se o caractere é minusculo

#include <iostream>
using namespace std;

bool caractere(char x);

int main()
{
    char c;

    cout<<"Digite um caractere:";
    cin>>c;

    if(caractere(c)==true)
        cout<<"O caractere é uma vogal minúscula";
    else
        cout<<"O caractere não é uma vogal minúscula";

    return 0;
}
bool caractere(char x)
{
    if((x=='a')||(x=='e')||(x=='i')||(x=='o')||(x=='u'))
        return true;
    else
        return false;
}
