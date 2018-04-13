#include <iostream>

using namespace std;

int main()
{
    double preco,dinheiroVendas[12],maiorVenda=-1000,mesVenda,total=0;
    int qntdVendas[12];
    cout<<"Insira o preço do tablet:";
    cin>>preco;

    while(preco<0)
    {
        cout<<"Erro.Digite um valor válido:";
        cin>>preco;
    }
    for(int i=0; i<12; i++)
    {
        cout<<"Digite a quantidade de tablets vendidos no mês"<<(i+1)<<":";
        cin>>qntdVendas[i];
        dinheiroVendas[i]=qntdVendas[i]*preco;
        if(dinheiroVendas[i]>maiorVenda)
        {
            maiorVenda=dinheiroVendas[i];
            mesVenda=i;
        }
        total+=dinheiroVendas[i];  ///total=total+dinheiroVendas[i]
    }
    cout<<"Mês com maior venda:"<<(mesVenda+1)<<endl;
    cout<<"Quantidade de dinheiro do mês com maior venda:"<<maiorVenda<<endl;
    cout<<"Total arrecadado:"<<total<<endl;
}
