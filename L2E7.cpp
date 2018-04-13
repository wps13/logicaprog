#include <iostream>

using namespace std;

int main(){
    int num;

    cout << "Digite um número inteiro: ";
    cin >> num;

    if((num%3==0) && (num%4==0) && (num%5==0)){
    cout << "O número é divisível por 3, por 4 e por 5.";
    }
    else{
    cout << "O número não é divisível por 3, por 4 e por 5.";
    }
return 0;
}
