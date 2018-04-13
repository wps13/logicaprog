//inverte num e compara
#include <iostream>
#include <cmath>
using namespace std;

bool maiorInvertido(int a,int b);
int inverteNumero(int w);

int main()
{
    int n1,n2;

    cout<<"Insira dois números:";
    cin>>n1>>n2;

    if(maiorInvertido(n1,n2)==true)
        cout<<n1<<" é maior que "<<n2<<" invertido.";
    else
        cout<<n2<<" é maior que "<<n1<<" invertido.";

}
int inverteNumero(int w)
{
    int soma=0,exp,a=0,b=1000;
    while(b>=1)
    {
        soma+=(w/b)*pow(10,a);
        a++;
        b/=10;
    }
}
bool maiorInvertido(int a,int b)
{
    int s1,s2;
    s1=inverteNumero(a);
    s2=inverteNumero(b);
    if(s1>s2)
        return true;
    else
        return false;
}
