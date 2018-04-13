//converter caracteres para maiusculos

#include <iostream>
#define tam 50
using namespace std;

int main()
{

    char s1[tam];
    int n;

    cout<<"Digite o tamanho da cadeia:";
    cin>>n;
    cout<<"Digite uma cadeia de caracteres:";
    for(int i=0;i<n;i++)
    {
        cin>>s1[i];
        s1[i]=toupper(s1[i]);

    }
    cout<<s1;

}
