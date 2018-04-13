#include <iostream>

using namespace std;

int main(){
	int l1,l2,l3;
	cout<<"Digite o valor do Lado 1:";
	cin>>l1;
	cout<<"Digite o valor do Lado 2:";
	cin>>l2;
	cout<<"Digite o valor do Lado 3:";
	cin>>l3;
	
	if((l1<l2+l3)&&(l2<l1+l3)&&(l3<l1+l2))
	{
	if((l1==l2)&&(l2==l3))
	cout<<"Forma um triângulo equilátero.";
	if((l1==l2)||(l2==l3))
	cout<<"Forma um triângulo isósceles.";
	if((l1!=l2)&&(l2!=l3))
	cout<<"Forma um triângulo escaleno.";
	}
	else
	cout<<"Não forma um triângulo.";
	}
