#include <iostream>
#include <cstring>
#include <ctype.h>
#define tam 500
using namespace std;

bool carac(char s1[],int tamS1)
{
    int cont=0;
    for(int i=0; i<tamS1; i++)
    {
        if(isalpha(s1[i]))
            cont++;
        if(s1[i]==' ')
        cont++;
    }

    if(cont==tamS1)
        return true;
    else
        return false;
}

int main()
{
    char str1[tam];
    int tamstr;

    cout<<"Insira a string desejada:";
    cin.getline(str1,tam);

    tamstr=strlen(str1);

    if(carac(str1,tamstr)==true)
        cout<<"A string é formada apenas por vogais.";
    else
        cout<<"A string não é formada apenas por vogais.";
}
