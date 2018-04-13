#include <iostream>

using namespace std;

int main(){

    int num1,num2,mdc;
    float resto;


    cout<<"Digite o primeiro número: ";
    cin>>num1;
    cout<<"Digite o segundo número: ";
    cin>>num2;

    resto=num1%num2;

    while(resto != 0)
{

    num1 = num2;
    num2 = resto;
    resto=num1%num2;

}
    cout<<"O máximo divisor comum é: "<<num2;
    return 0;
}
