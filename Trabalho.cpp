#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int main()
{
    char numCarta[] {'4','4','4','4','5','5','5','5','6','6','6','6','7','7','7','7','Q','Q','Q','Q','J','J','J','J','K','K','K','K','A','A','A','A','2','2','2','2','3','3','3','3'};
    char naipCarta[] {'O','E','C','Z','O','E','C','Z','O','E','C','Z','O','E','C','Z','O','E','C','Z','O','E','C','Z','O','E','C','Z','O','E','C','Z','O','E','C','Z','O','E','C','Z'};
    int i,cartaEscolhida,posicaoVira;
    char mesaLetra[6],mesaNum[6],carta[3];
    char cartLetJog[3],cartNumJog[3];
    char viraNum,viraLetra,numManilha[4],naipManilha[4];

    srand(time(0));

    posicaoVira=rand()%39;
    viraNum=numCarta[posicaoVira];
    viraLetra=naipCarta[posicaoVira];
    //MANILHA
    while(viraNum==numCarta[posicaoVira]) //GERA A MANILHA AO PROCURAR POR UM CARACTERER DIFERENTE DO VIRA NO VETOR,AUMENTANDO A POSIÇÃO SE NECESSÁRIO
    {
        posicaoVira++;
    }
    if(posicaoVira>39)//QUANDO A POSIÇÃO CHEGA NA  ÚLTIMA POSIÇÃO,VOLTA PARA A PRIMEIRA
    {
        posicaoVira=0;
    }
    //DECLARANDO OS NAIPS DA MANILHA PRA SER USADO PARA COMPARAÇÃO DE QUEM VENCER NO CASO DE EMPATE DE NAIPS
    for(int i=0; i<4; i++)
    {
        numManilha[i]=numCarta[posicaoVira+i];
        naipManilha[i]=naipCarta[posicaoVira+i];
    }
    cout<<"VIRA: "<<viraNum<<" de "<<viraLetra<<endl;
    cout<<"MANILHA: "<<numManilha[0]<<endl;
    cout<<"Cartas do jogador:"<<endl;
    for(i=0; i<3; i++)
    {
        carta[i]=rand()%39;
        cartNumJog[i]=numCarta[carta[i]];
        cartLetJog[i]=naipCarta[carta[i]];
        while(carta[i]==carta[i+1])
        {
            carta[i+1]=rand()%39;
        }
        cout<<cartNumJog[i]<<" "<<cartLetJog[i]<<endl;

    }
    cout<<"Digite a carta escolhida:";
    cin>>cartaEscolhida;
    while(cartaEscolhida<1 || cartaEscolhida>3)
    {
        cout<<"Carta inválida.Digite novamente:";
        cin>>cartaEscolhida;
    }

    cartaEscolhida=cartaEscolhida-1;
    mesaNum[0]=cartNumJog[cartaEscolhida];
    mesaLetra[0]=cartLetJog[cartaEscolhida];
    cartNumJog[cartaEscolhida]=-1;
    cartLetJog[cartaEscolhida]=-1;

    cout<<"Mesa:"<<mesaNum[0]<<" "<<mesaLetra[0]<<endl;

    for(i=0; i<3; i++)
    {
        if(cartNumJog[i]==-1 && cartLetJog[i]==-1)
        {

        }
        cout<<cartNumJog[i]<<" "<<cartLetJog[i]<<endl;
    }
}