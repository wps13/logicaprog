#include <iostream>
#include <cmath>

using namespace std;

int main()
{

    int n;

    while(n != 0)
    {
        cout<<"Digite um número: ";
        cin>>n;
           n=pow(n,2);
        cout<<"Quadrado do número: "<< n<< endl;
    }
}
