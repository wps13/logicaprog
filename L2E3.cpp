#include <iostream>

using namespace std;

int main(){
	int numero;

	cout << "Digite um número: ";
	cin >> numero;

	if(numero > 20){
		cout << "Número maior que 20.";
	}
	else {
		if(numero == 20){
			cout << "Número igual a 20.";
		}
		else{
		cout << "Número menor que 20.";
		}
	}
return 0;
}
