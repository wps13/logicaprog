//calcula a potência de um número
#include <iostream>
using namespace std;

double potencia(double x,double y);

int main()
{
    double base,exp;

    cout<<"Digite a base e o expoente desejados:";
    cin>>base>>exp;

    cout<<base<<" ^ "<<exp<<" = "<<potencia(base,exp);

    return 0;
}
double potencia(double x,double y)
{
    double a=1;
    int p=1; //o trono usado começa em um
    if(y>=0)//caso em que o expoente é igual ou maior a zero
    {
        if(y==0) //se o expoente for zero,retorna 1
            return 1;
        for(int i=1; i<=y; i++)
        {
            p*=x; //calcula a potencia

        }
        return p;
    }
    else
    {
        x=(1.0/x);
        y*=(-1);
        for(int i=1; i<=y; i++)
        {
            a*=x; //calcula a potencia

        }
        return a;
    }
}
