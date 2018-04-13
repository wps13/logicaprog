#include <iostream>

using namespace std;

int main(){
    int n1, n2, n3;

    cout << "Digite três números: ";
    cin >> n1 >> n2 >> n3;

    if(n3 >= n1 && n3 <= n2){
    cout << "O número está contido no intervalo fechado.";
    }
    else{
    cout << "O número não está contido no intervalo fechado.";
    }
return 0;
}
