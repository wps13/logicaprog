//calcula mdc entre dois números
#include <iostream>
using namespace std;

int mdc(int x,int y);
int mmc(int q,int w);
int main()
{
    int a,b;

    cout<<"Digite os números para calcular o MDC:";
    cin>>a>>b;

    cout<<"MDC entre os números: "<<mdc(a,b)<<endl;
    cout<<"MMC entre os números: "<<mmc(a,b);

}
int mdc(int x,int y)
{
    int maior,resto,div;
    if(x>y)
    {
        maior=x;
        resto=x%y;
    }
    else
    {
        maior=y;
        resto=y%x;
    }
    while(div>0)
    {

        div=maior%resto;
        maior=resto;
        resto=div;
    }
    return maior;
}
int mmc(int q,int w)
{
    int m;
    m=((q*w)/mdc(q,w));

    return m;

}
