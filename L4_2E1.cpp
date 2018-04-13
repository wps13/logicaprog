#include <iostream>
using namespace std;
int main(){

int n,cont1,m,numPares,cont2,contPar,contTotal,contImpar;

cont1=m=contPar=contImpar=contTotal=0;

while(n){
	cout<<"Digite um número:";
	cin>>n;
	cont2++;
if((n<100) && (n>-100)){
	cont1++;
	cout<<"Quantidade de números menores que 100 e maiores que -100:"<<cont1;
}
if((n%5==0) && (n%7==0)){
	m=m+n;
	cout<<"Quantidade de números múltiplos de 5 e 7:"<<m;
}
if(n%2==0){
	numPares=numPares+n;
	contPar++;
	cout<<"Média dos números Pares:"<<numPares/contPar;
}
if(n%2 != 0){
	contImpar++;
	cout<<"Porcentagem de números ímpares do total:"<<(contImpar*100)/contTotal<<"%";
}
	contTotal++;
}
}
	


