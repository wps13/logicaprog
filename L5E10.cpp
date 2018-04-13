#include <iostream>
using namespace std;
int main()
{
    int vetA[7];
    int vetB[5];
    int vetC[12];
    int i,j;

    for(i=0; i<7; i++)
    {
        cout<<"Digite as componentes do vetor A:";
        cin>>j;
        vetA[i]=j;
    }

    for(i=0; i<5; i++)
    {
        cout<<"Digite as componentes do vetor B:";
        cin>>j;
        vetB[i]=j;
    }
    for(i=0; i<12; i++)
    {
        if(i<7)
            vetC[i]=vetA[i];
        else
            vetC[i]=vetB[i];

        cout<<vetC[i]<<endl;
    }


}
