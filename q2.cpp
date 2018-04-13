//TRANSFORMA SEGUNDOS EM HORAS,MINUTOS E SEGUNDOS
#include <iostream>
using namespace std;

int tempo(int n)
{
    int hora,minuto,seg;

    hora=n/3600;
    minuto=(n%3600)/60;
    seg=(n%3600)-(minuto*60);

    cout<<hora<<":"<<minuto<<":"<<seg;
}

int main()
{
    int s;
    cout<<"Digite a quantidade de segundos:";
    cin>>s;

    tempo(s);

    return 0;

}
