#include <iostream>

using namespace std;

    int main(){

    int ano;

    cout << "Digite o ano: ";
    cin >> ano;

    if(ano%4==0){
    cout << "Ano bissexto.";
    }
    else{
    if(!(ano%100==0)){
    cout << "Ano não bissexto.";
    }
    else{
    if(ano%400==0){
    cout << "Ano bissexto.";
    }
    else{
    cout << "O ano não é bissexto.";
    }
    }
}
}
