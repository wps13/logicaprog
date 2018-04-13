#include <iostream>

using namespace std;

int main()
{

    int n1,n2;
    float media;

    n1=0;
    n2=0;
    media=0;
    cout<<"Digite a primeira nota: ";
    cin>>n1;
    cout<<"Digite a segunda nota: ";
    cin>>n2;


    while((n1<0 || n1>10) || (n2<0 || n2>10))
    {
        cout<<"Nota inválida."<<endl;

        if(n1<0 || n1>10)
        {
            cout<<"Digite a primeira nota novamente :";
            cin>>n1;
        }
        else if(n2<0 || n2>10)
            cout<<"Digite a segunda nota novamente :";
        cin>>n2;

    }

    media=(n1+n2)/2;
    cout<<"A média é: "<<media<<endl;

}
