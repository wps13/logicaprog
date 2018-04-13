#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int a,b,c;

    cout<<"Digite três números: ";
    cin >>a>>b>>c;

if(a<b && a<c){
    cout << "O primeiro número é o menor.";
}
else{
    if(b<c){
        cout<<"O segundo número é o menor.";
    }
    else
    cout << "O terceiro número é o menor.";
}
}
