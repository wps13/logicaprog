#include <iostream>

using namespace std;

int main()
{
    int dia;

    while(dia<1 || dia>30)
    {
        cout<<"Digite um dia do mês de setembro: ";
        cin>>dia;
        cout<<"Dia inválido.Tente novamente."<<endl;

    }
    cout<<"Dia válido.";
}

