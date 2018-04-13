//testar se é o numero é par
#include <iostream>
using namespace std;

bool teste(int n);//protótipo da função

int main()
{
    int num;

    cout<<"Digite um número:";
    cin>>num;

    if(teste(num)==true)
        cout<<"O número é par.";
    else
        cout<<"O número não é par.";

    return 0;
}

bool teste(int n)
{
    if((n%2==0) && (n>0))
        return true;
    else
        return false;
}
