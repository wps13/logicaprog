#include <iostream>

using namespace std;

int main()
{
    int num;
    int cont=0;
    num=-1;
    while(num != 0){
        cout<<"Digite um número: ";
    cin>>num;

    if(num%3==0 || num%7==0)
        cont++;
        cout<<"Múltiplos de 3 ou 7: "<<cont<<endl;
        }
    return 0;
}
