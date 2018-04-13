//verifica se um ponto está dentro de um circulo
#include <iostream>
#include <cmath>
using namespace std;

bool teste(int raio,int x1,int x2,int c1,int c2)
{
    int d,x,y;
    x=pow(x1-c1,2);//subtrai o valor da coordenada x do circulo da do ponto
    y=pow(x2-c2,2);
    d=sqrt(x+y);//calcula a distância entre a circunferencia e o ponto dado

    if(d<=raio)
        return true;
    else
        return false;
}

int main()
{
    int r,centro1,centro2,x,y;
    cout<<"Digite o raio,as coordenadas do centro e as coordenadas do ponto:"<<endl;
    cin>>r>>centro1>>centro2>>x>>y;

    if(teste(r,centro1,centro2,x,y)==true)
        cout<<"O ponto está dentro do circulo";
    else
        cout<<"O ponto não está dentro do circulo";

    return 0;
}
