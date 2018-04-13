#include <iostream>

using namespace std;

int main()
{
    int num,i;
    int matricula[10] = {2, 0, 1, 5, 0, 1, 1, 9, 5, 3};

    cout<<"Digite um número entre 0 e 9:";
    cin>>num;
    cout<<"O número aparece nas seguintes posições:"<<endl;
    for(i=0; i<10; i++)
    {
      if(num==matricula[i])
      cout<<i<<endl;

      }
}
