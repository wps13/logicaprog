#include <iostream>

using namespace std;

int main(){

int numero;

cout << "Digite um ano: ";
cin>>numero;

if((numero%4==0) &&(!(numero%100==0)) || (numero%400==0)){
cout << "Ano bissexto.";
}
else{
cout << "ano não bissexto.";
}
}

