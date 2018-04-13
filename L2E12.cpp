#include <iostream>
#include <cmath>

using namespace std;
//Programa mostra classificação de acordo com imc
int main(){

	float altura;
	float massa;
	float imc;

	cout << "Digite a altura em metros: ";

	cin >> altura;

	cout << "Digite o peso em quilogramas: ";

	cin >> massa;

	imc = massa /pow(altura,2) ;

	if(imc < 18.5)
	cout <<"Abaixo do peso.";
	else{
	if(imc >= 18.5 && imc <= 24.9){
	cout << "Peso normal.";
	}
	else{
	if(imc >= 25.0 && imc <= 29.9){
	cout << "Sobrepeso.";
	}
	else{
	cout << "Obesidade.";
	}
	}
	}
return 0;
}
