#include <iostream>
using namespace std;

int main(){
	int num;
	
	cout<<"Digite a quantidade de minutos:";
	cin>>num;
	
	cout<<num/1440<<" dias,"<<((num%1440)/60)<<" horas e "<<((num%1440)%60)<<" minutos";
	
	}
