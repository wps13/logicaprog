#include <iostream>

using namespace std;

int main()
{
    float n1,n2,nRep,media;

    cout<<"Digite as notas: ";
    cin>>n1>>n2;

    media = (n1*5 +n2*6)/11;

    if(media>=7)
    {
        cout<<"aprovado.";
    }
    else if(media<=3)
        cout<<"Reprovado";
    else
    {
        cout<<"Precisa da avaliação final."<<endl;
        cout<<"Digite a nota da avaliação final."<<endl;
        cin>>nRep;


        if(nRep>n1)
        {
            media = (nRep*5+n2*6)/11;
        }
        else
        {
            media = (n1*5+nRep*6)/11;
            if(media>=5)
                cout<<"Aprovado";
            else{
                cout<<"Reprovado.";
        }
    }
    }
}

