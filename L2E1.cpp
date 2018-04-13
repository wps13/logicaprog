#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char **argv)
{
	int numero;
	cout << "Digite um número: ";
	cin >> numero;
	
	if(numero > 0) {
    cout << sqrt(numero) ; 
	}	
    else {   
    cout << pow(numero,2);
    
	return 0;
		}
	}

