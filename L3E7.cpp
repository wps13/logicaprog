#include <iostream>

using namespace std;

int main()
{

    int num;
    num = -1;

    cout<<"Digite um número positivo: ";
    cin>>num;

    while(num<10000)
    {
        num = num*3;
        cout<<num<<endl;
    }
    return 0;
}
