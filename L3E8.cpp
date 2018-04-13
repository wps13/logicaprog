#include <iostream>

using namespace std;

int main()
{
    int cidadeA = 7000;
    int cidadeB = 20000;
    int ano;
    ano=0;
    while(cidadeA < cidadeB)
    {
        cidadeA=cidadeA +(cidadeA * 0.035);
        cidadeB=cidadeB + (cidadeB * 0.01);
        cout<<"Ano: "<<ano++<<endl;
        cout<<"População da cidade A: "<<cidadeA<<endl;
        cout<<"População da cidade B: "<<cidadeB<<endl;
    }
return 0;
}
