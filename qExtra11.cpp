#include <iostream>
#include <cstring>
#define tam 100
using namespace std;

void embaralha(char s1[],int tamS1,char s2[],int tamS2,char s3[])
{
    int i,j=0,k=0;
    for(i=0; i<(tamS1+tamS2); i++)
    {
        if(i%2==0)
        {
            s3[i]=s1[j];
            j++;
        }
        else
        {
            s3[i]=s2[k];
            k++;
        }

        if(s1[j]=='\0')
            s3[i]=s2[k];
        else if(s2[k]=='\0')
            s3[i]=s1[j];
    }
    s3[i]=0;
}

int main()
{
    char str1[tam],str2[tam],str3[tam];
    int tamStr1,tamStr2;

    cout<<"Primeira string:";
    cin.getline(str1,tam);
    cout<<"Segunda string:";
    cin.getline(str2,tam);

    tamStr1=strlen(str1);
    tamStr2=strlen(str2);

    embaralha(str1,tamStr1,str2,tamStr2,str3);

    cout<<str3;


}
