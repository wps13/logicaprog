#include <iostream>
#include<cstdlib>
#include<ctime>
#include <unistd.h>
using namespace std;
int main()
{
    ///BARALHO
    char numCarta[40]= {'4','4','4','4','5','5','5','5','6','6','6','6','7','7','7','7','Q','Q','Q','Q','J','J','J','J','K','K','K','K','A','A','A','A','2','2','2','2','3','3','3','3'};
    char naipCarta[40] = {'O','E','C','Z','O','E','C','Z','O','E','C','Z','O','E','C','Z','O','E','C','Z','O','E','C','Z','O','E','C','Z','O','E','C','Z','O','E','C','Z','O','E','C','Z'};
    char numCartaUsadaJ1[3],numCartaUsadaJ2[3],compararNaipManiCartJog1, compararNaipManiCartJog2;
    char naipCartaUsadaJ1[3],naipCartaUsadaJ2[3],vencedorMao[30];
    ///VARIÁVEIS
    int pontuacaoJog1=0, pontuacaoJog2=0, posManilha, ok1[3], ok2[3], pos1, pos2, Rodada[3],mao=0, posNaipCartaJog1, posNaipCartaJog2, modoJogo=1;
    int vitJogador, posicaoVira, posCartJog1[3], posCartJog2[3], cartEscolhidaJog1[3], cartEscolhidaJog2[3], opcao, VencDes, cont, cont2,mao11;
    char viraLetra, cartLetJog1[3], cartLetJog2[3], viraNum, cartNumJog1[3], cartNumJog2[3],numManilha[4],naipManilha[4], nomeJ1[25] {'J','o','g','a','d','o','r',' ','1'}, nomeJ2[25] {'J','o','g','a','d','o','r',' ','2'};
    srand(time(0));
///JOGO COMPLETO

    cout<<"               ████████╗██████╗ ██╗   ██╗ ██████╗ ██████╗ "<<endl;
    cout<<"               ╚══██╔══╝██╔══██╗██║   ██║██╔════╝██╔═══██╗"<<endl;
    cout<<"                  ██║   ██████╔╝██║   ██║██║     ██║   ██║"<<endl;
    cout<<"                  ██║   ██╔══██╗██║   ██║██║     ██║   ██║"<<endl;
    cout<<"                  ██║   ██║  ██║╚██████╔╝╚██████╗╚██████╔╝ "<<endl;
    cout<<"                  ╚═╝   ╚═╝  ╚═╝ ╚═════╝  ╚═════╝ ╚═════╝  "<<endl;
    cout<<"                \n\t\t\t\t\t\tSeja Bem vindo!"<<endl;
    sleep(3);
    system("clear");
    do
    {
        cout<<"\033[22;32m#MENU: \n Iniciar novo jogo\t\t(1)\n Mudar nome dos jogadores\t(2)\n Mudar modo de jogo\t\t(3)\n Carregar jogo\t\t\t(4)\n Sair do jogo\t\t\t(5)\nInforme: ";
        cin>>opcao;
        while(opcao==2 || opcao==3)
        {
            if(opcao==2)
            {
                system("clear");
                cout<<"\033[22;35m\nDigite o nome do primeiro jogador."<<endl;
                cin.getline(nomeJ1,24);
                cin.getline(nomeJ1,24);
                if(modoJogo==1)
                {
                    cout<<"\nDigite o nome do segundo jogador."<<endl;
                    cin.getline(nomeJ2,24);
                }
            }
            if(opcao==3)
            {
                system("clear");
                cout<<" Humano x Humano\t(1)\n Humano x Computador\t(2)"<<endl;
                cin>>modoJogo;
                system("clear");
                cout<<"\033[22;32m#MENU: \n Iniciar novo jogo\t\t(1)\n Mudar nome dos jogadores\t(2)\n Mudar modo de jogo\t\t(3)\n Carregar jogo\t\t\t(4)\n Sair do jogo\t\t\t(5)\nInforme: ";
                cin>>opcao;
            }
            system("clear");
            cout<<"\033[22;32m#MENU: \n Iniciar novo jogo\t\t(1)\n Mudar nome dos jogadores\t(2)\n Mudar modo de jogo\t\t(3)\n Carregar jogo\t\t\t(4)\n Sair do jogo\t\t\t(5)\nInforme: ";
            cin>>opcao;
        }
        int b,l;
        for(l=0; nomeJ2[l]!='\0' ; l++)
            nomeJ2[l]=toupper(nomeJ2[l]);
        for(b=0; nomeJ1[b]!='\0'; b++)
            nomeJ1[b]=toupper(nomeJ1[b]);
        if(opcao==1 && modoJogo==1)
        {
            pontuacaoJog1=pontuacaoJog2=0;
            vitJogador=12;
            system("clear");
            while(pontuacaoJog1<12 && pontuacaoJog2<12)
            {
                int ValTruco=0, EscTruco;
                system("clear");
                cout<<"\t\tPLACAR"<<endl;
                cout<<nomeJ1<<": "<<pontuacaoJog1<<endl;
                cout<<nomeJ2<<": "<<pontuacaoJog2<<endl;
                for(int i=0; i<3; i++) ///Inicia os vetores que armazenam as cartas(tanto número quanto naipe) dos dois jogadores
                {
                    ok1[i]=ok2[i]=0;
                    Rodada[i]=-1;
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
                    cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> RODADA "<<(i+1)<<" <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<endl;
                    if(vitJogador==21 && i!=0)
                        cout<<"Rodada "<<i<<" vencida por "<<nomeJ2<<endl;
                    else if(vitJogador==12 && i!=0)
                        cout<<"Rodada "<<i<<" vencida por "<<nomeJ1<<endl;
                    if(vitJogador==12)
                    {
                        cout<<"===============================[ VEZ DE "<<nomeJ1<<" ]=================================="<<endl;
                        cout<<"VIRA: "<<viraNum<<" : "<<viraLetra<<endl;
                        cout<<"MANILHA: "<<numManilha[0]<<endl;
                        if(pontuacaoJog1<11)
                            cout<<"Para TRUCAR:0(Zero)"<<endl;
                        do
                        {
                            cout<<"Escolha uma carta das cartas abaixo "<<nomeJ1<<"! "<<endl;
                            for(int j=0; j<3; j++)
                            {
                                if(ok1[j]==0 && (pontuacaoJog1!=11 || pontuacaoJog2!=11))
                                    cout<<cartNumJog1[j]<<" : "<<cartLetJog1[j]<<"  ("<<(j+1)<<")"<<endl;
                                if(ok1[j]==0 && (pontuacaoJog1==11 && pontuacaoJog2==11 ))
                                    cout<<"X : X"<<" ("<<(j+1)<<")"<<endl;
                            }
                            cin >> pos1;
                            if(pontuacaoJog1=11)
                            {
                                cout<<"Deseja jogar essa mão?:\nSim(1)\nNão(2)";
                                cin>>mao11;
                                if(mao11==1)

                                if(mao11==2)
                                    {
                                        i+=2;
                                        pontuacaoJog2++;
                                    }
                            }
                            EscTruco=pos1;
                            while(EscTruco==0 && ValTruco<=9 && pontuacaoJog1<=11 && pontuacaoJog2<=11)
                            {
                                system("clear");
                                cout<<"VIRICE!!"<<endl;
                                system("PAUSE");
                                system("clear");
                                cout<<"TRUCO! Aceita ? Sim (1), Nao(2), Trucar(0)\nSuas cartas:"<<endl;
                                for(int j=0; j<3; j++)
                                {
                                    if(ok2[j]==0)
                                        cout<<" "<<cartNumJog2[j]<<" : "<<cartLetJog2[j]<<"  ("<<(j+1)<<")"<<endl;
                                }
                                cin>>EscTruco;
                                if(EscTruco==1 || EscTruco==0)
                                    ValTruco+=3;
                                if(EscTruco==2)
                                {
                                    Rodada[0]=Rodada[1]=1;
                                    EscTruco=-1;
                                    break;
                                }
                                if(EscTruco==1)
                                {
                                    cout<<"VIRICE!!"<<endl;
                                    system("PAUSE");
                                    system("clear");
                                    cout<<"Escolha uma carta das cartas abaixo "<<nomeJ1<<"! "<<endl;
                                    for(int j=0; j<3; j++)
                                    {
                                        if(ok1[j]==0)
                                            cout<<" "<<cartNumJog1[j]<<" : "<<cartLetJog1[j]<<"  ("<<(j+1)<<")"<<endl;
                                    }
                                    cin>>pos1;
                                    system("clear");
                                    EscTruco=pos1;
                                }
                            }
                            pos1--;
                            if(EscTruco==-1)
                                break;
                        }
                        while(pos1<0 || pos1>2 || ok1[pos1]==1);
                        if(EscTruco==-1)
                            break;
                        ok1[pos1]=1;
                        posNaipCartaJog1=posCartJog1[pos1];
                        system("clear");
                        cout<<"Carta usada por "<<nomeJ1<<": "<<cartNumJog1[pos1]<<" - "<<cartLetJog1[pos1]<<endl;
                    }
                    ///===================================================================================================================
                    ///VEZ DO JOGADOR 2
                    if(vitJogador==21 || vitJogador==12)
                    {
                        cout<<"===============================[ VEZ DE "<<nomeJ2<<" ]=================================="<<endl;
                        cout<<"VIRA: "<<viraNum<<" : "<<viraLetra<<endl;
                        cout<<"MANILHA: "<<numManilha[0]<<endl<<endl;
                        do
                        {
                            cout<<"Escolha uma carta das cartas abaixo "<<nomeJ2<<"! "<<endl;
                            for(int j=0; j<3; j++)
                            {
                                if(ok2[j]==0)
                                    cout<<cartNumJog2[j]<<" : "<<cartLetJog2[j]<<"  ("<<(j+1)<<")"<<endl;
                            }
                            cin >> pos2;
                            EscTruco=pos2;
                            while(EscTruco==0 && ValTruco<=9 && pontuacaoJog1<=11 && pontuacaoJog2<=11)
                            {
                                system("clear");
                                cout<<"VIRICE!!"<<endl;
                                system("PAUSE");
                                system("clear");
                                cout<<"TRUCO! Aceita ? Sim (1), Nao(2), Trucar(0)"<<endl;
                                for(int j=0; j<3; j++)
                                {
                                    if(ok1[j]==0)
                                        cout<<" "<<cartNumJog1[j]<<" : "<<cartLetJog1[j]<<"  ("<<(j+1)<<")"<<endl;
                                }
                                cin>>EscTruco;
                                if(EscTruco==1 || EscTruco==0)
                                    ValTruco+=3;
                                if(EscTruco==2)
                                {
                                    Rodada[0]=Rodada[1]=2;
                                    EscTruco=-1;
                                    break;
                                }
                                if(EscTruco==1)
                                {
                                    cout<<"VIRICE!!"<<endl;
                                    system("PAUSE");
                                    system("clear");
                                    cout<<"Escolha uma carta das cartas abaixo "<<nomeJ2<<"! "<<endl;
                                    for(int j=0; j<3; j++)
                                    {
                                        if(ok2[j]==0)
                                            cout<<cartNumJog2[j]<<" : "<<cartLetJog2[j]<<"  ("<<(j+1)<<")"<<endl;
                                    }
                                    cin>>pos2;
                                    system("clear");
                                    EscTruco=pos2;
                                }
                            }
                            pos2--;
                            if(EscTruco==-1)
                                break;
                        }
                        while(pos2<0 || pos2>2 || ok2[pos2]==1);
                        if(EscTruco==-1)
                            break;
                        ok2[pos2]=1;
                        posNaipCartaJog2=posCartJog2[pos2];
                        system("clear");
                        if(vitJogador==21)
                            cout<<"Carta usada por "<<nomeJ2<<": "<<cartNumJog2[pos2]<<" - "<<cartLetJog2[pos2]<<endl;
                    }
                    if(vitJogador==21)
                    {
                        cout<<"===============================[ VEZ DE "<<nomeJ1<<" ]=================================="<<endl;
                        cout<<"VIRA: "<<viraNum<<" : "<<viraLetra<<endl;
                        cout<<"MANILHA: "<<numManilha[0]<<endl<<endl;
                        do
                        {
                            cout<<"Escolha uma carta das cartas abaixo "<<nomeJ1<<"! "<<endl;
                            for(int j=0; j<3; j++)
                            {
                                if(ok1[j]==0)
                                    cout<<cartNumJog1[j]<<" : "<<cartLetJog1[j]<<"  ("<<(j+1)<<")"<<endl;
                            }
                            cin >> pos1;
                            EscTruco=pos1;
                            while(EscTruco==0 && ValTruco<=9 && pontuacaoJog1<=11 && pontuacaoJog2<=11)
                            {
                                system("clear");
                                cout<<"VIRICE!!"<<endl;
                                system("PAUSE");
                                system("clear");
                                cout<<"TRUCO! Aceita ? Sim (1), Nao(2), Trucar(0)"<<endl;
                                for(int j=0; j<3; j++)
                                {
                                    if(ok2[j]==0)
                                        cout<<" "<<cartNumJog2[j]<<" : "<<cartLetJog2[j]<<"  ("<<(j+1)<<")"<<endl;
                                }
                                cin>>EscTruco;
                                if(EscTruco==1 || EscTruco==0)
                                    ValTruco+=3;
                                if(EscTruco==2)
                                {
                                    Rodada[0]=Rodada[1]=1;
                                    EscTruco=-1;
                                    break;
                                }
                                if(EscTruco==1)
                                {
                                    cout<<"VIRICE!!"<<endl;
                                    system("PAUSE");
                                    system("clear");
                                    cout<<"Escolha uma carta das cartas abaixo "<<nomeJ1<<"! "<<endl;
                                    for(int j=0; j<3; j++)
                                    {
                                        if(ok1[j]==0)
                                            cout<<cartNumJog1[j]<<" : "<<cartLetJog1[j]<<"  ("<<(j+1)<<")"<<endl;
                                    }
                                    cin>>pos1;
                                    system("clear");
                                    EscTruco=pos1;
                                }
                            }
                            pos1--;
                            if(EscTruco==-1)
                                break;
                        }
                        while(pos1<0 || pos1>2 || ok1[pos1]==1);
                        if(EscTruco==-1)
                            break;
                        ok1[pos1]=1;
                        posNaipCartaJog1=posCartJog1[pos1];
                        system("clear");
                    }
                    ///AVALIANDO QUAL DOS JOGADORES VENCEU A RODADA (PRIMEIRA PARTE)
                    compararNaipManiCartJog2=cartNumJog2[pos2];
                    compararNaipManiCartJog1=cartNumJog1[pos1];
                    if((compararNaipManiCartJog2==compararNaipManiCartJog1 && compararNaipManiCartJog1==numManilha[0] && posNaipCartaJog1>posNaipCartaJog2) || (compararNaipManiCartJog1!=compararNaipManiCartJog2 && compararNaipManiCartJog1==numManilha[0] && compararNaipManiCartJog2!=numManilha[0]) || (compararNaipManiCartJog1!=compararNaipManiCartJog2 && compararNaipManiCartJog1!=numManilha[0] && compararNaipManiCartJog2!=numManilha[0] && posNaipCartaJog1>posNaipCartaJog2) || (VencDes==1 && EscTruco==-1))
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
                    if((compararNaipManiCartJog2==compararNaipManiCartJog1 && compararNaipManiCartJog1==numManilha[0] && posNaipCartaJog1<posNaipCartaJog2) || (compararNaipManiCartJog1!=compararNaipManiCartJog2 && compararNaipManiCartJog1!=numManilha[0] && compararNaipManiCartJog2==numManilha[0]) || (compararNaipManiCartJog1!=compararNaipManiCartJog2 && compararNaipManiCartJog2!=numManilha[0] && compararNaipManiCartJog1!=numManilha[0] && posNaipCartaJog2>posNaipCartaJog1) || (VencDes==2 && EscTruco==-1))
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
                    if(compararNaipManiCartJog1==compararNaipManiCartJog2 && compararNaipManiCartJog1!=numManilha[0])
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
                    if(Rodada[0]==Rodada[1])
                        break;
                    if(EscTruco==-1)
                        break;
                }
                if(ValTruco==0)
                    ValTruco=1;
                if(Rodada[0]==0 && Rodada[1]==0 && Rodada[2]==0)
                {
                    vencedorMao[mao]='n';
                }
                if((Rodada[0]==0 && Rodada[1]==0 && Rodada[2]==1) || (Rodada[0]==0 && Rodada[1]==1) || (Rodada[0]==1 && Rodada[1]==0) || (Rodada[0]==1 && Rodada[1]==1) || (Rodada[0]==1 && Rodada[1]==2 && Rodada[2]==0) || (Rodada[0]==1 && Rodada[1]==2 && Rodada[2]==1) || (Rodada[0]==2 && Rodada[1]==1 && Rodada[0]==1))
                {
                    pontuacaoJog1=pontuacaoJog1+ValTruco;
                    vencedorMao[mao]='P';
                }
                if((Rodada[0]==0 && Rodada[1]==0 && Rodada[2]==2) || (Rodada[0]==0 && Rodada[1]==2) || (Rodada[0]==1 && Rodada[1]==2 && Rodada[2]==2) || (Rodada[0]==2 && Rodada[1]==0) || (Rodada[0]==2 && Rodada[1]==1 && Rodada[0]==0) || (Rodada[0]==2 && Rodada[1]==1 && Rodada[0]==2) || (Rodada[0]==2 && Rodada[1]==2))
                {
                    pontuacaoJog2=pontuacaoJog2+ValTruco;
                    vencedorMao[mao]='S';
                }
                mao++;
            }
        }
        ///DESENVOLVIMENTO HUMANO X COMPUTADOR
        if(opcao==1 && modoJogo==2)
        {
            pontuacaoJog1=pontuacaoJog2=0;
            vitJogador=12;
            nomeJ2[0]='C',nomeJ2[1]='O', nomeJ2[2]='M',nomeJ2[3]='P', nomeJ2[4]='U',nomeJ2[5]='T', nomeJ2[6]='A',nomeJ2[7]='D',nomeJ2[8]='O',nomeJ2[9]='R';
            system("clear");
            while(pontuacaoJog1<12 && pontuacaoJog2<12)
            {
                int ValTruco=0, EscTruco;
                system("clear");
                cout<<"\t\tPLACAR"<<endl;
                cout<<nomeJ1<<": "<<pontuacaoJog1<<endl;
                cout<<nomeJ2<<": "<<pontuacaoJog2<<endl;
                for(int i=0; i<3; i++) ///Inicia os vetores que armazenam as cartas(tanto número quanto naipe) dos dois jogadores
                {
                    ok1[i]=ok2[i]=0;
                    Rodada[i]=-1;
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
                    cont=cont2=0;
                    cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> RODADA "<<(i+1)<<" <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<endl;
                    if(vitJogador==21 && i!=0)
                        cout<<"Rodada "<<i<<" vencida por "<<nomeJ2<<endl;
                    if(vitJogador==12 && i!=0)
                        cout<<"Rodada "<<i<<" vencida por "<<nomeJ1<<endl;
                    if(vitJogador==12)
                    {
                        cout<<"===============================[ VEZ DE "<<nomeJ1<<" ]=================================="<<endl;
                        cout<<"VIRA: "<<viraNum<<" : "<<viraLetra<<endl;
                        cout<<"MANILHA: "<<numManilha[0]<<endl;
                        if(pontuacaoJog1<11)
                            cout<<"Para TRUCAR: 0 (zero)"<<endl;
                        do
                        {
                            cout<<"Escolha uma carta das cartas abaixo "<<nomeJ1<<"! "<<endl;
                            for(int j=0; j<3; j++)
                            {
                                if(ok1[j]==0)
                                    cout<<cartNumJog1[j]<<" : "<<cartLetJog1[j]<<"  ("<<(j+1)<<")"<<endl;
                            }
                            cin >> pos1;
                            EscTruco=pos1;
                            while(EscTruco==0 && ValTruco<=9 && pontuacaoJog1<=11 && pontuacaoJog2<=11)
                            {
                                if(cont2%2!=0)
                                {
                                    system("clear");
                                    cout<<"TRUCO! Aceita ? Sim (1), Nao(2), Trucar(0)"<<endl;
                                    cin>>EscTruco;
                                }
                                else
                                    EscTruco=rand()%2;
                                if(EscTruco==1 || EscTruco==0)
                                    ValTruco+=3;
                                if(EscTruco==2)
                                {
                                    Rodada[0]=Rodada[1]=1;
                                    EscTruco=-1;
                                    break;
                                }
                                if(EscTruco==1)
                                {
                                    if(cont2%2!=0)
                                    {
                                        system("clear");
                                        cout<<"Escolha uma carta das cartas abaixo "<<nomeJ1<<"! "<<endl;
                                        for(int j=0; j<3; j++)
                                        {
                                            if(ok1[j]==0)
                                                cout<<cartNumJog1[j]<<" : "<<cartLetJog1[j]<<"  ("<<(j+1)<<")"<<endl;
                                        }
                                        system("clear");
                                        cin>>pos1;
                                    }
                                    else
                                        pos1=rand()%3;
                                    EscTruco=pos1;
                                }
                                cont2++;
                            }
                            pos1--;
                            if(EscTruco==-1)
                                break;
                        }
                        while(pos1<0 || pos1>2 || ok1[pos1]==1);
                        if(EscTruco==-1)
                            break;
                        ok1[pos1]=1;
                        posNaipCartaJog1=posCartJog1[pos1];
                        system("clear");
                        cout<<"Carta usada por "<<nomeJ1<<": "<<cartNumJog1[pos1]<<" - "<<cartLetJog1[pos1]<<endl;
                    }
                    ///===================================================================================================================
                    ///VEZ DO JOGADOR 2
                    if(vitJogador==21 || vitJogador==12)
                    {
                        do
                        {
                            pos2=rand()%3;
                            EscTruco=pos2;
                            while(EscTruco==0 && ValTruco<=9 && pontuacaoJog1<=11 && pontuacaoJog2<=11)
                            {
                                if(cont%2==0)
                                {
                                    system("clear");
                                    cout<<"TRUCO! Aceita ? Sim (1), Nao(2), Trucar(0)"<<endl;
                                    cin>>EscTruco;
                                }
                                else
                                    EscTruco==rand()%2;
                                if(EscTruco==1 || EscTruco==0)
                                    ValTruco+=3;
                                if(EscTruco==2)
                                {
                                    Rodada[0]=Rodada[1]=2;
                                    EscTruco=-1;
                                    break;
                                }
                                cont++;
                            }
                            pos2--;
                            if(EscTruco==-1)
                                break;
                        }
                        while(pos2<0 || pos2>2 || ok2[pos2]==1);
                        if(EscTruco==-1)
                            break;
                        ok2[pos2]=1;
                        posNaipCartaJog2=posCartJog2[pos2];
                        system("clear");
                        if(vitJogador==21)
                            cout<<"Carta usada por "<<nomeJ2<<": "<<cartNumJog2[pos2]<<" - "<<cartLetJog2[pos2]<<endl;
                    }
                    if(vitJogador==21)
                    {
                        cout<<"===============================[ VEZ DE "<<nomeJ1<<" ]=================================="<<endl;
                        cout<<"VIRA: "<<viraNum<<" : "<<viraLetra<<endl;
                        cout<<"MANILHA: "<<numManilha[0]<<endl<<endl;
                        do
                        {
                            cout<<"Escolha uma carta das cartas abaixo "<<nomeJ1<<"! "<<endl;
                            for(int j=0; j<3; j++)
                            {
                                if(ok1[j]==0)
                                    cout<<cartNumJog1[j]<<" : "<<cartLetJog1[j]<<"  ("<<(j+1)<<")"<<endl;
                            }
                            cin >> pos1;
                            EscTruco=pos1;
                            while(EscTruco==0 && ValTruco<=9 && pontuacaoJog1<=11 && pontuacaoJog2<=11)
                            {
                                if(cont2%2!=0)
                                {
                                    system("clear");
                                    cout<<"TRUCO! Aceita ? Sim (1), Nao(2), Trucar(0)"<<endl;
                                    cin>>EscTruco;
                                }
                                else
                                    EscTruco=rand()%2;
                                if(EscTruco==1 || EscTruco==0)
                                    ValTruco+=3;
                                if(EscTruco==2)
                                {
                                    Rodada[0]=Rodada[1]=1;
                                    EscTruco=-1;
                                    break;
                                }
                                if(EscTruco==1)
                                {
                                    if(cont2%2!=0)
                                    {
                                        system("clear");
                                        cout<<"Escolha uma carta das cartas abaixo "<<nomeJ1<<"! "<<endl;
                                        for(int j=0; j<3; j++)
                                        {
                                            if(ok1[j]==0)
                                                cout<<cartNumJog1[j]<<" : "<<cartLetJog1[j]<<"  ("<<(j+1)<<")"<<endl;
                                        }
                                        system("clear");
                                        cin>>pos1;
                                    }
                                    else
                                        pos1=rand()%3;
                                    EscTruco=pos1;
                                }
                                cont2++;
                            }
                            pos1--;
                            if(EscTruco==-1)
                                break;
                        }
                        while(pos1<0 || pos1>2 || ok1[pos1]==1);
                        if(EscTruco==-1)
                            break;
                        ok1[pos1]=1;
                        posNaipCartaJog1=posCartJog1[pos1];
                        system("clear");
                    }
                    ///AVALIANDO QUAL DOS JOGADORES VENCEU A RODADA (PRIMEIRA PARTE)
                    compararNaipManiCartJog2=cartNumJog2[pos2];
                    compararNaipManiCartJog1=cartNumJog1[pos1];
                    if((compararNaipManiCartJog2==compararNaipManiCartJog1 && compararNaipManiCartJog1==numManilha[0] && posNaipCartaJog1>posNaipCartaJog2) || (compararNaipManiCartJog1!=compararNaipManiCartJog2 && compararNaipManiCartJog1==numManilha[0] && compararNaipManiCartJog2!=numManilha[0]) || (compararNaipManiCartJog1!=compararNaipManiCartJog2 && compararNaipManiCartJog1!=numManilha[0] && compararNaipManiCartJog2!=numManilha[0] && posNaipCartaJog1>posNaipCartaJog2) || (VencDes==1 && EscTruco==-1))
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
                    if((compararNaipManiCartJog2==compararNaipManiCartJog1 && compararNaipManiCartJog1==numManilha[0] && posNaipCartaJog1<posNaipCartaJog2) || (compararNaipManiCartJog1!=compararNaipManiCartJog2 && compararNaipManiCartJog1!=numManilha[0] && compararNaipManiCartJog2==numManilha[0]) || (compararNaipManiCartJog1!=compararNaipManiCartJog2 && compararNaipManiCartJog2!=numManilha[0] && compararNaipManiCartJog1!=numManilha[0] && posNaipCartaJog2>posNaipCartaJog1) || (VencDes==2 && EscTruco==-1))
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
                    if(compararNaipManiCartJog1==compararNaipManiCartJog2 && compararNaipManiCartJog1!=numManilha[0])
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
                    if(Rodada[0]==Rodada[1])
                        break;
                    if(EscTruco==-1)
                        break;
                }
                if(ValTruco==0)
                    ValTruco=1;
                if(Rodada[0]==0 && Rodada[1]==0 && Rodada[2]==0)
                {
                    vencedorMao[mao]='n';
                }
                if((Rodada[0]==0 && Rodada[1]==0 && Rodada[2]==1) || (Rodada[0]==0 && Rodada[1]==1) || (Rodada[0]==1 && Rodada[1]==0) || (Rodada[0]==1 && Rodada[1]==1) || (Rodada[0]==1 && Rodada[1]==2 && Rodada[2]==0) || (Rodada[0]==1 && Rodada[1]==2 && Rodada[2]==1) || (Rodada[0]==2 && Rodada[1]==1 && Rodada[0]==1))
                {
                    pontuacaoJog1=pontuacaoJog1+ValTruco;
                    vencedorMao[mao]='P';
                }
                if((Rodada[0]==0 && Rodada[1]==0 && Rodada[2]==2) || (Rodada[0]==0 && Rodada[1]==2) || (Rodada[0]==1 && Rodada[1]==2 && Rodada[2]==2) || (Rodada[0]==2 && Rodada[1]==0) || (Rodada[0]==2 && Rodada[1]==1 && Rodada[0]==0) || (Rodada[0]==2 && Rodada[1]==1 && Rodada[0]==2) || (Rodada[0]==2 && Rodada[1]==2))
                {
                    pontuacaoJog2=pontuacaoJog2+ValTruco;
                    vencedorMao[mao]='S';
                }
                mao++;
            }
        }
        if(opcao == 1)
        {
            cout<<"\t\tTABELA DE MAOS"<<endl;
            for(int i=0; i<mao; i++)
            {
                cout<<"Mao "<<(i +1)<<": "<<vencedorMao[i]<<endl;
            }
            cout<<"\nPLACAR GERAL: "<<endl;
            cout<<nomeJ1<<": "<<pontuacaoJog1<<endl;
            cout<<nomeJ2<<": "<<pontuacaoJog2<<endl;
            if(pontuacaoJog1>pontuacaoJog2)
            {
                cout<<"\nVencedor: "<<nomeJ1<<"!!\n\n"<<endl;
            }
            if(pontuacaoJog1<pontuacaoJog2)
            {
                cout<<"\nVencedor: "<<nomeJ2<<"!!\n\n"<<endl;
            }
            cout<<" ____   __    ____    __    ____  _  _  ___    _  _  ____  _  _  ___  ____  ____  _____  ____   /\\ "<<endl;
            cout<<"(  _ \\ /__\\  (  _ \\  /__\\  (  _ \\( \\( )/ __)  ( \\/ )( ___)( \\( )/ __)( ___)(  _ \\(  _  )(  _ \\  )("<<endl;
            cout<<" )___//(__)\\  )   / /(__)\\  ) _ < )  ( \\__ \\   \\  /  )__)  )  (( (__  )__)  )(_) ))(_)(  )   /  \\/"<<endl;
            cout<<"(__) (__)(__)(_)\\_)(__)(__)(____/(_)\\_)(___/    \\/  (____)(_)\\_)\\___)(____)(____/(_____)(_)\\_)  ()"<<endl;
            sleep(3);
            system("clear");
        }
        if(opcao==4)
        {
            cout<<"\033[22;31m\nDisponível somente na versão premium."<<endl;
        }
        if(opcao==5)
        {
            break;
        }
        opcao=1;
    }
    while(opcao!=5);
}
///FALTAM:
///cor dos nomes
///salvar jogo


