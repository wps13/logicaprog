#include <iostream>

using namespace std;

int main()
{
    char texto[51];
    char vogal;
    int cont;


    cout<<"Digite um texto:";
    cin.getline(texto,50);

    cout<<"Digite uma vogal:";
    cin>>vogal;

    cont=-1;
    cout<<"Posições que a vogal aparece:"<<endl;
    for(int i=0; texto[i]!='\0'; i++)
    {
        if(texto[i]==vogal)
        {
          cout<<i<<endl;
            cont++;
        }

    }
    cout<<"Quantidade de vezes que a vogal aparece:"<<cont<<endl;


}
