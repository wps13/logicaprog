#include <iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int ok1[3], ok2[3], pos1, pos2;

int main()
{
    ///BARALHO
    char numCarta[40]= {'4','4','4','4','5','5','5','5','6','6','6','6','7','7','7','7','Q','Q','Q','Q','J','J','J','J','K','K','K','K','A','A','A','A','2','2','2','2','3','3','3','3'};
    char naipCarta[40] = {'O','E','C','Z','O','E','C','Z','O','E','C','Z','O','E','C','Z','O','E','C','Z','O','E','C','Z','O','E','C','Z','O','E','C','Z','O','E','C','Z','O','E','C','Z'};
    char numCartaUsadaJ1[3],numCartaUsadaJ2[3],compararNaipManiCartJog1, compararNaipManiCartJog2;
    char naipCartaUsadaJ1[3],naipCartaUsadaJ2[3],vencedorMao[30];
    ///VARIÁVEIS
    int pontuacaoJog1=0, pontuacaoJog2=0, posManilha;
    int vitJogador=12, posicaoVira, posCartJog1[3], posCartJog2[3], cartEscolhidaJog1[3], cartEscolhidaJog2[3];
    int Rodada[3],mao=0, posNaipCartaJog1, posNaipCartaJog2;
    char viraLetra, cartLetJog1[3], cartLetJog2[3], viraNum, cartNumJog1[3], cartNumJog2[3],numManilha[4],naipManilha[4];
    srand(time(0));

///JOGO COMPLETO
    while(pontuacaoJog1<12 && pontuacaoJog2<12)
    {

        for(int i=0; i<3; i++) ///Inicia os vetores que armazenam as cartas(tanto número quanto naipe) dos dois jogadores
        {
            ok1[i]=ok2[i]=0;
            numCartaUsadaJ1[i]='0'; ///Usando int ou char ainda dá erro
            numCartaUsadaJ2[i]='0';
            naipCartaUsadaJ1[i]='0';
            naipCartaUsadaJ2[i]='0';
            cartNumJog1[i]='0';
            cartNumJog2[i]='0';
            cartLetJog1[i]='0';
            cartLetJog2[i]='0';

        }

        posicaoVira=rand()%39;
        posManilha=posicaoVira;
        viraNum=numCarta[posicaoVira];
        viraLetra=naipCarta[posicaoVira];
        ///MANILHA
        while(viraNum==numCarta[posManilha]) ///GERA A MANILHA AO PROCURAR POR UM CARACTERER DIFERENTE DO VIRA NO VETOR,AUMENTANDO A POSIÇÃO SE NECESSÁRIO
        {
            posManilha++;
        }
        if(posManilha>39)///QUANDO A POSIÇÃO CHEGA NA  ÚLTIMA POSIÇÃO,VOLTA PARA A PRIMEIRA
        {
            posManilha=0;
        }
        ///DECLARANDO OS NAIPS DA MANILHA PRA SER USADO PARA COMPARAÇÃO DE QUEM VENCER NO CASO DE EMPATE DE NAIPS
        for(int i=0; i<4; i++)
        {
            numManilha[i]=numCarta[posManilha+i];
            naipManilha[i]=naipCarta[posManilha+i];
        }
        ///CARTA DO JOGADOR 01 e 02
        for(int i=0; i<3; i++)
        {
            posCartJog1[i]=rand()%39;
            posCartJog2[i]=rand()%39;
            while(posCartJog1[0]==posCartJog2[0] || posCartJog1[0]==posCartJog2[1] || posCartJog1[0]==posCartJog2[2] || posCartJog1[1]==posCartJog2[0] || posCartJog1[1]==posCartJog2[1] || posCartJog1[1]==posCartJog2[2] || posCartJog1[2]==posCartJog2[0] || posCartJog1[2]==posCartJog2[1] || posCartJog1[2]==posCartJog2[2] || posCartJog2[0]==posCartJog2[1] || posCartJog2[0]==posCartJog2[2] || posCartJog2[1]==posCartJog2[2] || posCartJog1[0]==posCartJog1[1] || posCartJog1[0]==posCartJog1[2] || posCartJog1[1]==posCartJog1[2])
                ///Compara as cartas do jogadores,caso alguma seja igual,ele gera uma nova carta
            {
                posCartJog1[i]=rand()%39;
                posCartJog2[i]=rand()%39;
            }

            cartNumJog1[i]=numCarta[posCartJog1[i]]; ///Armazena as letras e naipes das cartas de cada jogador
            cartLetJog1[i]=naipCarta[posCartJog1[i]];
            cartNumJog2[i]=numCarta[posCartJog2[i]];
            cartLetJog2[i]=naipCarta[posCartJog2[i]];
        }
        for(int i=0; i<3; i++)///Inicia a mão
        {
            cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> RODADA "<<(i+1)<<" <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<endl;
            cout<<"\nVIRA: "<<viraNum<<" : "<<viraLetra<<endl;
            cout<<"MANILHA: "<<numManilha[0]<<endl;

            if(vitJogador==12)
            {
                for(int j=0; j<3; j++)
                {
                    if(ok1[j]==0)
                        cout<<cartNumJog1[j]<<" : "<<cartLetJog1[j]<<"  ("<<(j+1)<<")"<<endl;
                }
                cout<<"Escolha uma carta das cartas acima! "<<endl;
                do
                {
                    cin >> pos1;
                    pos1--;

                }
                while(pos1<0 || pos1>2 || ok2[pos1]==1);
                ok1[pos1]=1;
                posNaipCartaJog1=posCartJog1[pos1];
                system("clear");
                cout<<"Carta usada pelo primeiro jogador: "<<cartNumJog1[pos1]<<" - "<<cartLetJog1[pos1]<<endl;
                cout<<"VIRA: "<<viraNum<<" : "<<viraLetra<<endl;
                cout<<"MANILHA: "<<numManilha[0]<<endl;
            }
            ///===================================================================================================================
            ///VEZ DO JOGADOR 2
            if(vitJogador==21 || vitJogador==12)
            {
                for(int j=0; j<3; j++)
                {
                    if(ok2[j]==0)
                        cout<<cartNumJog2[j]<<" : "<<cartLetJog2[j]<<"  ("<<(j+1)<<")"<<endl;
                }
                cout<<"Escolha uma carta das cartas acima! "<<endl;
                do
                {
                    cin >> pos2;
                    pos2--;
                }
                while(pos2<0 || pos2>2 || ok2[pos2]==1);
                ok2[pos2]=1;
                posNaipCartaJog2=posCartJog2[pos2];
                system("clear");
                cout<<"Carta usada pelo primeiro jogador: "<<cartNumJog2[pos2]<<" - "<<cartLetJog2[pos2]<<endl;
            }
            if(vitJogador==21)
            {
                cout << "sdaiashdau\n";
                for(int j=0; j<3; j++)
                {
                    if(ok1[j]==0)
                        cout<<cartNumJog1[j]<<" : "<<cartLetJog1[j]<<"  ("<<(j+1)<<")"<<endl;
                }
                cout<<"Escolha uma carta das cartas acima! "<<endl;
                do
                {
                    cin >> pos1;
                    pos1--;

                }
                while(pos1<0 || pos1>2 || ok1[pos1]==1);
                ok1[pos1]=1;
                posNaipCartaJog1=posCartJog1[pos1];
                cout<<"Carta usada pelo primeiro jogador: "<<cartNumJog1[pos1]<<" - "<<cartLetJog1[pos1]<<endl;
                system("clear");
            }
            //=====================================================================================================================
            ///AVALIANDO QUAL DOS JOGADORES VENCEU A RODADA (PRIMEIRA PARTE)
            compararNaipManiCartJog2=cartNumJog2[pos2];
            compararNaipManiCartJog1=cartNumJog1[pos1];
            if(compararNaipManiCartJog2==compararNaipManiCartJog1 && compararNaipManiCartJog1==numManilha[0])
            {
                if(posNaipCartaJog1>posNaipCartaJog2)
                {
                    for(int r=0; r<3; r++)
                    {
                        if(i==r)
                        {
                            Rodada[r]=1;
                            vitJogador=12;
                        }
                    }
                }
                else if(posNaipCartaJog1<posNaipCartaJog2)
                {
                    for(int r=0; r<3; r++)
                    {
                        if(i==r)
                        {
                            Rodada[r]=2;
                            vitJogador=21;
                        }
                    }
                }
            }
            else
            {
                if(posNaipCartaJog1>posNaipCartaJog2 && compararNaipManiCartJog1!=compararNaipManiCartJog2)
                {
                    for(int r=0; r<3; r++)
                    {
                        if(i==r)
                        {
                            Rodada[r]=1;
                            vitJogador=12;
                        }
                    }
                }
                else if(posNaipCartaJog1<posNaipCartaJog2 && compararNaipManiCartJog1!=compararNaipManiCartJog2)
                {
                    for(int r=0; r<3; r++)
                    {
                        if(i==r)
                        {
                            Rodada[r]=2;
                            vitJogador=21;
                        }
                    }
                }
                else if(compararNaipManiCartJog1==compararNaipManiCartJog2 && compararNaipManiCartJog1!=numManilha[0])
                {
                    for(int r=0; r<3; r++)
                    {
                        if(i==r)
                        {
                            Rodada[r]=0;
                            if(vitJogador==21)
                            {
                                vitJogador=12;
                            }
                            else if(vitJogador=12)
                            {
                                vitJogador=21;
                            }
                        }
                    }
                }
            }
        }
        if(Rodada[0]==0 && Rodada[1]==0 && Rodada[2]==0)
        {
            vencedorMao[mao]='n';
        }
        if((Rodada[0]==0 && Rodada[1]==0 && Rodada[2]==1) || (Rodada[0]==0 && Rodada[1]==1) || (Rodada[0]==1 && Rodada[1]==0) || (Rodada[0]==1 && Rodada[1]==1) || (Rodada[0]==1 && Rodada[1]==2 && Rodada[2]==0) || (Rodada[0]==1 && Rodada[1]==2 && Rodada[2]==1) || (Rodada[0]==2 && Rodada[1]==1 && Rodada[0]==1))
        {
            pontuacaoJog1++;
            vencedorMao[mao]='P';
        }
        if((Rodada[0]==0 && Rodada[1]==0 && Rodada[2]==2) || (Rodada[0]==0 && Rodada[1]==2) || (Rodada[0]==1 && Rodada[1]==2 && Rodada[2]==2) || (Rodada[0]==2 && Rodada[1]==0) || (Rodada[0]==2 && Rodada[1]==1 && Rodada[0]==0) || (Rodada[0]==2 && Rodada[1]==1 && Rodada[0]==2) || (Rodada[0]==2 && Rodada[1]==2))
        {
            pontuacaoJog2++;
            vencedorMao[mao]='S';
        }

        mao++;
    }
    cout<<"\t\tTABELA DE MAOS"<<endl;
    for(int i=0; i<mao; i++)
    {
        cout<<"Mao "<<(i +1)<<": "<<vencedorMao[i]<<endl;
    }
    if(pontuacaoJog1>pontuacaoJog2)
    {
        cout<<"\n\n\t\t\t\t\tParabéns Primeiro Jogador!!\n\n"<<endl;
    }
    if(pontuacaoJog1<pontuacaoJog2)
    {
        cout<<"\n\n\t\t\t\t\tParabéns Segundo Jogador!!\n\n"<<endl;
    }
}

