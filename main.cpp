#include <iostream>
using namespace std;
int main()
{
    char nome[100],f='F',m='M',ultNome[30],sexo,posicao;
    int i,j;

    cout<<"Digite o nome:";
    cin.getline(nome,99);
    cout<<"Digite o seu sexo(M ou F):";
    cin>>sexo;

    for(i=0;nome[i]!='\0';i++){
         if(nome[i]!= ' ')
         {
         posicao=i;
         }
}
for(j=0,i=posicao+1;nome != '\0';i++,j++)
{
ultNome[j]=nome[i];
}
    if(sexo==f)
        cout<<"Bom dia Sra. "<<ultNome;
    if(sexo==m)
        cout<<"Bom dia Sr. "<<ultNome;

}
