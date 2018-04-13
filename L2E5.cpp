#include <iostream>

using namespace std;

int main(){
    float consumo, conta;

    cout << "Digite o consumo de água(em metros cúbicos): ";
    cin >> consumo;

    if(consumo < 20){
    conta = consumo * 8.50;
    cout << "O valor da conta é:R$ " << conta;
    }
    else{
    conta = consumo*11.0;
    cout << "O valor da conta é:R$ " << conta;
    }
return 0;
}
