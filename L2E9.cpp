#include <iostream>

using namespace std;

int main(){
    float deposito, saldo; //saldo será o valor pago pelo banco

    cout << "Digite a quantia referente ao deposito:R$ "; //o programa vai calcular o rendimento do deposito
    cin >> deposito;

    if(deposito < 1000.0){
    saldo = deposito*0.04;
    cout <<"Rendimento:R$ " << saldo;
    }
    else{
    if(deposito >= 1000.0 && deposito < 5000.0){
    saldo = deposito*0.045;
    cout << "Rendimento:R$ " << saldo;
    }
    else{
    saldo = deposito*0.05;
    cout << "Rendimento:R$ " << saldo;
    }
    }
return 0;
}
