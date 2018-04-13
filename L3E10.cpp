#include <iostream>

using namespace std;

int main(){
	int cont;
	float massa;
	
	cout<<"Digite a massa do material radioativo:";
	cin>>massa;
	
	cont=0;
	while(massa>0.5)
	{
		massa=massa/2;
		cont++;			//cada contagem do contagem é uma meiavida - 50s
	}
	cout<<"Tempo para o material atingir 0,5g: "<<((cont*50)/60)<<" min "<<((cont*50)%60)<<" s";
}
