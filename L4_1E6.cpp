#include <iostream>
using namespace std;

int main(){

int n;
cout<<"Digite um número entre 1 e 9:";
cin>>n;

cout<<"Tabuado do número inserido:"<<endl;
for(int i=1;i<=9;i++)
cout<<n<<"X"<<i<<"="<<n*i<<endl;

}
