//calcula nota recuperacao e a menor delas
#include <iostream>
using namespace std;

double menorNota(double nt1,double nt2,double nt3);

double calcNota(double n1,double n2,double n3);

int main()
{
    double nota1,nota2,nota3;

    cout<<"Insira as notas do aluno:";
    cin>>nota1>>nota2>>nota3;

    cout<<"Menor nota do aluno:"<<menorNota(nota1,nota2,nota3)<<endl;
    cout<<"nota necessaria para passar:"<<calcNota(nota1,nota2,nota3);

}
double menorNota(double nt1,double nt2,double nt3)
{
    double menor;
    if((nt1<nt2) && (nt1<nt3))
        menor=nt1;
    else if(nt2<nt3)
        menor=nt2;
    else
        menor=nt3;

    return menor;
}
double calcNota(double n1,double n2,double n3)
{
    double rec,soma;
    soma=(n1+n2+n3) - menorNota(n1,n2,n3);
    rec=15-soma;

    return rec;
}
