///EQUIPE: João Pedro Silva(5A),Hygor Felype(5B) e Willane Paiva(5B)
///onde tiver sleep(3) -> Sleep(3000),system("clear") -> system("cls")
#include <iostream>
#include <cstdlib> 
#include <ctime>
#include <unistd.h>  ///<Windows.h>

using namespace std;

int main()
{
    ///BARALHO
    char numCarta[40]= {'4','4','4','4','5','5','5','5','6','6','6','6','7','7','7','7','Q','Q','Q','Q','J','J','J','J','K','K','K','K','A','A','A','A','2','2','2','2','3','3','3','3'};
    char naipCarta[40] = {'O','E','C','Z','O','E','C','Z','O','E','C','Z','O','E','C','Z','O','E','C','Z','O','E','C','Z','O','E','C','Z','O','E','C','Z','O','E','C','Z','O','E','C','Z'};
    ///VARIÁVEIS
    char compararNaipManiCartJog1, compararNaipManiCartJog2,vencedorMao[30],mao_de;
    int pontuacaoJog1=0,mod,decisao, pontuacaoJog2=0, posManilha, ok1[3], ok2[3], pos1, pos2, Rodada[3],mao=0, posNaipCartaJog1, posNaipCartaJog2, modoJogo=1;
    int vitJogador, posicaoVira, posCartJog1[3], posCartJog2[3], opcao, VencDes, cont, cont2;
    char viraLetra, cartLetJog1[3], cartLetJog2[3], viraNum, cartNumJog1[3], cartNumJog2[3],numManilha[4],naipManilha[4], nomeJ1[25]= {'J','o','g','a','d','o','r',' ','1'}, nomeJ2[25]= {'J','o','g','a','d','o','r',' ','2'};
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
                cout<<"\033[22;35m\n\nDigite o nome do primeiro jogador."<<endl;
                cin.ignore();
                cin.getline(nomeJ1,24);
                if(modoJogo==1)
                {
                    cout<<"\033[22;35m\n\nDigite o nome do segundo jogador."<<endl;
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
        int b,l; ///variavéis usadas como índices para poder armazenar os nomes dos jogadores em vetores de caracteres
        for(l=0; nomeJ2[l]!='\0' ; l++)
            nomeJ2[l]=toupper(nomeJ2[l]);
        for(b=0; nomeJ1[b]!='\0'; b++)
            nomeJ1[b]=toupper(nomeJ1[b]);

        if(opcao==1 && modoJogo==1)///Inicia o jogo para o modo humanoxhumano
        {
            pontuacaoJog1=pontuacaoJog2=0;
            vitJogador=12;///Força o jogo a iniciar com o primeiro jogador
            mao=0;
            system("clear");
            while(pontuacaoJog1<12 && pontuacaoJog2<12)
            {
                int ValTruco=0, EscTruco, decisao=0;///Váriaveis usadas para armazenar o valor do truco,qual foi a escolha do jogador(se aceita ou não,ou se truca novamente)
                mao_de='N'; ///Considera que a mão a ser jogada é a 'normal'
                system("clear");
                cout<<"PLACAR:  ";
                cout<<nomeJ1<<" "<<pontuacaoJog1<<" x "<<pontuacaoJog2<<" "<<nomeJ2;
                cout<<"\t\t\t\t\tMao:"<<mao+1<<endl;///Exibe a mão que está sendo jogada
                for(int i=0; i<3; i++) ///Inicia os vetores que testam se a carta já foi jogada
                {
                    ok1[i]=ok2[i]=0;
                    Rodada[i]=-1;
                }
                posicaoVira=rand()%39;///Gera uma carta aleatória para o vida
                posManilha=posicaoVira;///A variável que representa a posição da manilha vai receber a posição do vira para depois gerar o vira
                viraNum=numCarta[posicaoVira]; ///Gera o número da carta vira
                viraLetra=naipCarta[posicaoVira];///Gera o naipe da carta vira
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
                if(pontuacaoJog1==11 && pontuacaoJog2!=11) ///Se a pontuação do jogador 1  for 11 mas  a do outro não(mão de onze),ele exibe as cartas para ele decidir se vai jogar ou não
                {
                    cout<<nomeJ1<<",suas cartas:"<<endl;
                    for(int j=0; j<3; j++)
                    {
                        cout<<" "<<cartNumJog1[j]<<" : "<<cartLetJog1[j]<<"  ("<<(j+1)<<")"<<endl;
                    }
                    cout<<endl<<nomeJ1<<", você alcançou 11 pontos primeiro:\n Iniciar\t(1)\n Pular mao\t(2)"<<endl;
                    cin>>decisao;
                    while(decisao!=1 && decisao!=2)
                    {
                        system("clear");
                        cout<<"Opção Inválida.Informe novamente:\n Iniciar\t(1)\n Pular mao\t(2)"<<endl;
                        cin>>decisao;
                    }
                    if(decisao==1)///Caso decida jogar, a mao passa a valer 3
                    {
                        ValTruco=3;
                        mao_de='O';
                    }
                    if(decisao==2)///caso desista,o outro jogador ganha um ponto e pulado para a outra mao
                    {
                        pontuacaoJog2++;
                        vitJogador=21;
                    }
                }
                if(pontuacaoJog1!=11 && pontuacaoJog2==11)///Exibe as cartas do jogador 2 na mão de onze e pergunda se ele vai jogar ou não
                {
                    cout<<nomeJ2<<",suas cartas:"<<endl;
                    for(int j=0; j<3; j++)
                    {
                        cout<<cartNumJog2[j]<<" : "<<cartLetJog2[j]<<"  ("<<(j+1)<<")"<<endl;
                    }
                    cout<<nomeJ2<<", você alcançou 11 pontos primeiro:\n Iniciar\t(1)\n Pular mao\t(2)"<<endl;
                    cin>>decisao;
                    while(decisao!=1 && decisao!=2)///Força o jogador a escolher entre jogar ou pular a mão
                    {
                        system("clear");
                        cout<<"Opção inválida.Informe novamente:\n Iniciar\t(1)\n Pular mao\t(2)"<<endl;
                        cin>>decisao;
                    }
                    if(decisao==1)///Muda o valor da mão caso o jogador decida jogar e usa uma variavel para validação posteriormente
                    {
                        ValTruco=3;
                        mao_de='O';
                    }
                    if(decisao==2)///O outro jogador recebe a pontuação e  é iniciada uma nova mão
                    {
                        pontuacaoJog1++;
                        vitJogador=12;
                    }
                }
                if(pontuacaoJog1==11 && pontuacaoJog2==11)///Mão de ferro
                    mao_de='F';
                if(decisao!=2)
                {
                    for(int i=0; i<3; i++)///Inicia a mão
                    {
                        cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> RODADA "<<(i+1)<<" <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<endl;
                        if(vitJogador==21 && i!=0)
                            cout<<"Rodada "<<i<<" vencida por "<<nomeJ2<<endl;
                        else if(vitJogador==12 && i!=0)
                            cout<<"Rodada "<<i<<" vencida por "<<nomeJ1<<endl;
                        if(vitJogador==12)
                        {
                            cout<<"===============================[ VEZ DE "<<nomeJ1<<" ]=================================="<<endl;
                            cout<<"VIRA: "<<viraNum<<" : "<<viraLetra;
                            if(pontuacaoJog1<11 && pontuacaoJog2<11)///Só exibe a opção de truco caso os jogadores tenham menos de 11pts
                                cout<<"\t\t\t\t\tTRUCAR: 0 (zero)"<<endl;
                            cout<<"MANILHA: "<<numManilha[0]<<endl;
                            do
                            {
                                cout<<"Escolha uma carta das cartas abaixo "<<nomeJ1<<"! "<<endl;
                                for(int j=0; j<3; j++)
                                {
                                    if(ok1[j]==0 && mao_de!='F')///Caso não seja a mão de ferro,ele exibe as cartas normalmente
                                        cout<<cartNumJog1[j]<<" : "<<cartLetJog1[j]<<"  ("<<(j+1)<<")"<<endl;
                                    if(ok1[j]==0 && mao_de=='F')///Na mão de ferro,substitui a exibição da carta por 'x'
                                        cout<<"X : X ("<<(j+1)<<")"<<endl;
                                }
                                cin >> pos1;
                                while(mao_de=='O' && pos1==0 )///Caso mão de onze,não permite realizar o truco
                                {
                                    cout<<"MAO DE 11, portanto nao se pode escolher truco! Digite novamente!"<<endl;
                                    cin >> pos1;
                                }
                                while(mao_de=='F' && pos1==0 )///Caso mão de ferro,não permite realizar o truco
                                {
                                    cout<<"MÃO DE FERRO, portanto não se pode escolher truco! Digite novamente!"<<endl;
                                    cin >> pos1;
                                }
                                EscTruco=pos1;
                                mod=0;
                                while(EscTruco==0 && ValTruco<=9 && pontuacaoJog1<11 && pontuacaoJog2<11)
                                {
                                    system("clear");
                                    cout<<"TRUCO! Aceita ? Sim (1), Nao(2), Trucar(0)"<<endl;
                                    if(mod%2==0)///exibe a opção para o outro jogador escolher se vai querer o truco
                                    {
                                        cout<<"Suas cartas "<<nomeJ2<<":"<<endl;
                                        for(int j=0; j<3; j++)
                                        {
                                            if(ok2[j]==0)
                                                cout<<" "<<cartNumJog2[j]<<" : "<<cartLetJog2[j]<<"  ("<<(j+1)<<")"<<endl;
                                        }
                                    }
                                    else
                                    {
                                        cout<<"Suas cartas "<<nomeJ1<<":"<<endl;
                                        for(int j=0; j<3; j++)
                                        {
                                            if(ok1[j]==0)
                                                cout<<" "<<cartNumJog1[j]<<" : "<<cartLetJog1[j]<<"  ("<<(j+1)<<")"<<endl;
                                        }
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
                                    mod++;
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
                            cout<<"VIRA: "<<viraNum<<" : "<<viraLetra;
                            if(pontuacaoJog1<11 && pontuacaoJog2<11)///Só exibe a opção de truco caso os jogadores tenham menos de 11pts
                                cout<<"\t\t\t\t\tTRUCAR: 0 (zero)"<<endl;
                            cout<<"MANILHA: "<<numManilha[0]<<endl;
                            do
                            {
                                cout<<"Escolha uma carta das cartas abaixo "<<nomeJ2<<"! "<<endl;
                                for(int j=0; j<3; j++)
                                {
                                    if(ok2[j]==0 && mao_de!='F')
                                        cout<<" "<<cartNumJog2[j]<<" : "<<cartLetJog2[j]<<"  ("<<(j+1)<<")"<<endl;
                                    if(ok2[j]==0 && mao_de=='F')
                                        cout<<" "<<"X : X ("<<(j+1)<<")"<<endl;
                                }
                                cin >> pos2;
                                while(mao_de=='O' && pos2==0)
                                {
                                    cout<<"MAO DE 11, portanto nao se pode escolher truco! Digite novamente!"<<endl;
                                    cin >> pos2;
                                }
                                while(mao_de=='F' && pos2==0 )///Teste
                                {
                                    cout<<"MÃO DE FERRO, portanto nao se pode escolher truco! Digite novamente!"<<endl;
                                    cin >> pos2;
                                }
                                EscTruco=pos2;
                                mod=0;
                                while(EscTruco==0 && ValTruco<=9 && pontuacaoJog1<=11 && pontuacaoJog2<=11)
                                {
                                    system("clear");
                                    cout<<"TRUCO! Aceita ? Sim (1), Nao(2), Trucar(0)"<<endl;
                                    if(mod%2==0)
                                    {
                                        cout<<"Suas cartas "<<nomeJ1<<":"<<endl;
                                        for(int j=0; j<3; j++)
                                        {
                                            if(ok1[j]==0)
                                                cout<<" "<<cartNumJog1[j]<<" : "<<cartLetJog1[j]<<"  ("<<(j+1)<<")"<<endl;
                                        }
                                    }
                                    else
                                    {
                                        cout<<"Suas cartas "<<nomeJ2<<":"<<endl;
                                        for(int j=0; j<3; j++)
                                        {
                                            if(ok2[j]==0)
                                                cout<<" "<<cartNumJog2[j]<<" : "<<cartLetJog2[j]<<"  ("<<(j+1)<<")"<<endl;
                                        }
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
                                    mod++;
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
                            cout<<"VIRA: "<<viraNum<<" : "<<viraLetra;
                            if(pontuacaoJog1<11 && pontuacaoJog2<11)
                                cout<<"\t\t\t\t\tTRUCAR: 0 (zero)"<<endl;
                            cout<<"MANILHA: "<<numManilha[0]<<endl<<endl;
                            do
                            {
                                cout<<"Escolha uma carta das cartas abaixo "<<nomeJ1<<"! "<<endl;
                                for(int j=0; j<3; j++)
                                {
                                    if(ok1[j]==0 && mao_de!='F')
                                        cout<<" "<<cartNumJog1[j]<<" : "<<cartLetJog1[j]<<"  ("<<(j+1)<<")"<<endl;
                                    if(ok1[j]==0 && mao_de=='F')
                                        cout<<" "<<"X : X ("<<(j+1)<<")"<<endl;
                                }
                                cin >> pos1;
                                while(mao_de=='O' && pos1==0)
                                {
                                    cout<<"MAO DE 11, portanto nao se pode escolher truco! Digite novamente!"<<endl;
                                    cin >> pos1;
                                }
                                while(mao_de=='F' && pos1==0 )///Teste
                                {
                                    cout<<"MÃO DE FERRO, portanto nao se pode escolher truco! Digite novamente!"<<endl;
                                    cin >> pos1;
                                }
                                EscTruco=pos1;
                                mod=0;
                                while(EscTruco==0 && ValTruco<=9 && pontuacaoJog1<11 && pontuacaoJog2<11)
                                {
                                    system("clear");
                                    cout<<"TRUCO! Aceita ? Sim (1), Nao(2), Trucar(0)\nSuas cartas:"<<endl;
                                    if(mod%2==0)
                                    {
                                        cout<<"Suas cartas "<<nomeJ2<<":"<<endl;
                                        for(int j=0; j<3; j++)
                                        {
                                            if(ok2[j]==0)
                                                cout<<" "<<cartNumJog2[j]<<" : "<<cartLetJog2[j]<<"  ("<<(j+1)<<")"<<endl;
                                        }
                                    }
                                    else
                                    {
                                        cout<<"Suas cartas "<<nomeJ1<<":"<<endl;
                                        for(int j=0; j<3; j++)
                                        {
                                            if(ok1[j]==0)
                                                cout<<" "<<cartNumJog1[j]<<" : "<<cartLetJog1[j]<<"  ("<<(j+1)<<")"<<endl;
                                        }
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
                                    mod++;
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
///Decide o vencedor da rodada através do naipe do jogador e da manilha,além de comparar com a outro jogador
                        {
                            for(int r=0; r<3; r++)
                            {
                                if(i==r)
                                {
                                    Rodada[r]=1;
                                    vitJogador=12;/// O jogador 1 recebe esse valor que serve apenas para indicar a ordem de jogada
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
                                    else if(vitJogador==12)
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
                }
                if(ValTruco==0)
                    ValTruco=1;
                if(Rodada[0]==0 && Rodada[1]==0 && Rodada[2]==0)///Não pontua ninguém em caso de nenhuma vitoria nas rodadas
                {
                    vencedorMao[mao]='n';
                }
                if((Rodada[0]==0 && Rodada[1]==0 && Rodada[2]==1) || (Rodada[0]==0 && Rodada[1]==1) || (Rodada[0]==1 && Rodada[1]==0) || (Rodada[0]==1 && Rodada[1]==1) || (Rodada[0]==1 && Rodada[1]==2 && Rodada[2]==0) || (Rodada[0]==1 && Rodada[1]==2 && Rodada[2]==1) || (Rodada[0]==2 && Rodada[1]==1 && Rodada[0]==1))
                {
                    ///Testa e pontua o jogador 1 caso vencedor
                    pontuacaoJog1=pontuacaoJog1+ValTruco;
                    vencedorMao[mao]='P';
                }
                if((Rodada[0]==0 && Rodada[1]==0 && Rodada[2]==2) || (Rodada[0]==0 && Rodada[1]==2) || (Rodada[0]==1 && Rodada[1]==2 && Rodada[2]==2) || (Rodada[0]==2 && Rodada[1]==0) || (Rodada[0]==2 && Rodada[1]==1 && Rodada[0]==0) || (Rodada[0]==2 && Rodada[1]==1 && Rodada[0]==2) || (Rodada[0]==2 && Rodada[1]==2))
                {
                    pontuacaoJog2=pontuacaoJog2+ValTruco;
                    vencedorMao[mao]='S';
                }
                mao++;///atualiza a mão
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
                        if(pontuacaoJog1<11 && pontuacaoJog2<11)
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
                            while(EscTruco==0 && ValTruco<=9 && pontuacaoJog1<11 && pontuacaoJog2<11)
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
                                    EscTruco=rand()%2;
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
                            while(EscTruco==0 && ValTruco<=9 && pontuacaoJog1<11 && pontuacaoJog2<11)
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
                                else if(vitJogador==12)
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
