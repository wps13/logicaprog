#include <iostream>

using namespace std;

int main(){
    int num;

    cout << "Digite um número inteiro: ";
    cin >> num;

    if((num%3==0) || (num%4==0) || (num%5==0)){
    cout << "O número é divisível.";
    }
    else{
    cout << "Não divisível.";
    }
return 0;
}
