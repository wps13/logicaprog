//calcula o valor da função exponencial

#include <iostream>
#include <cmath>

using namespace std;

float exponencial(int x);

int main()
{
    int exp;
    cout<<"Digite a potência do exponencial:";
    cin>>exp;

    cout<<"O valor de e ^ "<<exp<<" = "<<exponencial(exp);

    return 0;
}
float exponencial(int x)
{
    float e=0;
    int fat=1;
    int i=1;

    while(e>0.0000001)
    {
        for(int j=1;j<=i;j++)
        {
            fat*=j;
        }

        e+=(pow(x,i)/fat);
        i++;
    }
    return e;

}

