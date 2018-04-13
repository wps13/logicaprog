#include <iostream>

using namespace std;

int main(){

    int incremento;
    float celsius, farenheit;

    cout<<"Digite o incremento para a temperatura Celsius: ";
    cin>>incremento;

    cout<<"Tabela de equivalências de temperaturas: "<<endl;
    celsius = 0;
    while(celsius < 100)
{
    celsius = celsius + incremento;
    farenheit= ((9*celsius)/5) + 32;
    cout<<"Celsius "<<celsius<<" Farenheit "<<farenheit<<endl;

}
}
