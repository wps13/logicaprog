#include <iostream> //Calcula raizes de equação
#include <cmath>

using namespace std;

int main(){
    int a,b,c;
    float equacao1, equacao2;
    float delta;

    cout << "Digite os coeficientes da equação de 2º grau: ";
    cin>>a>>b>>c;

    delta = (pow(b,2)-(4*a*c));
    equacao1 = (-(b+(sqrt(delta))))/(2*a);
    equacao2 = (-(b-(sqrt(delta))))/(2*a);

    if(delta>0){
        cout<<"X1= " <<equacao1 << " ,X2= " << equacao2;
    }
    else{
        if(delta==0){
            cout<<"X1=X2 = " <<equacao1;
        }
        else{
        cout<<"Não existem raizes.";

        }
    }
    }
