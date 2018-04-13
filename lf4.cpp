//testar se o caractere é uma consoante

#include <iostream>
using namespace std;

bool caractere(char y);

int main()
{
    char carac;

    cout<<"Digite um caractere:";
    cin>>carac;

    if(caractere(carac)==true)
        cout<<"O caractere digitado é uma consoante.";
    else
        cout<<"O caractere digitado não é uma consoante.";
}

bool caractere(char y)
{
    int t=y;

    if((t>=65 || t<=90) || (t>=97 || t<=122))
    {
        if((t==65)||(t==69)||(t==73)||(t==79)||(t==85)||(t==97)||(t==101)||(t==105)||(t==111)||(t==117))
            return false;
        else
            return true;
    }
    else
        return false;

}
