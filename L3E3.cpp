#include <iostream>

using namespace std;
//receber reais positivos e calcular quadrado se maior que 15
int main()
{
    float n;

    while(n != -4) //para em -4
    {
        cout<<"Digite um número: ";
        cin>>n;

        if(n>15)
        {
            n=n*n;
            cout<<"Quadrado do número: "<<n<<endl;
        }
    }
}
