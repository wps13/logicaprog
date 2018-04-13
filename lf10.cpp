//calcula a hora,minuto e segundos dado os segundos
#include <iostream>
using namespace std;

int tempo(int s);

int main()
{
    int segundos;
    cout<<"Digite a quantidade de segundos:";
    cin>>segundos;
    tempo(segundos);

    return 0;
}
int tempo(int s)
{
    int hora,minu,seg;
    hora=s/3600;
    minu=(s%3600)/60;
    seg=(s%3600)%60;
    cout<<hora<<" hora(s), "<<minu<<" minuto(s), e "<<seg<<" segundo(s)";

}
