#include <iostream>

using namespace std;
int main()
{
    int notaAtleta,somaNotas=0,maior=0,menor=10,i;
    int notas[5];

    cout<<"Digite as notas do salto(Entre 0 e 10):";
    cin>>notas[0]>>notas[1]>>notas[2]>>notas[3]>>notas[4];

for(i=0; i<5; i++){
    if(notas[i]>maior)//A maior nota será armazenada aqui
        maior=notas[i];
    if(notas[i]<menor)//A menor nota será armazenada aqui
        menor=notas[i];
}
    for(i=0; i<5; i++)
        somaNotas+=notas[i];

    notaAtleta=(somaNotas-maior-menor)/3; //A nota é feita com média de 3 notas,sem a menor e maior
cout<<"A nota do atleta é:"<<notaAtleta;

}
