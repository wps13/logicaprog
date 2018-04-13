#include <iostream>
using namespace std;
int main()
{
    char pal1[21],pal2[21];
    int i;
    cout<<"Digite a primeira palavra:";
    cin.getline(pal1,20);
    cout<<"Digite a segunda palavra:";
    cin.getline(pal2,20);
    for(i=0; pal1[i]!= '\0' && pal2[i]!= '\0'; i++)
    {
        if(pal1[i]!=pal2[i])
        {
            cout<<"\nAs palavras são diferentes!\n";
            break;
        }
    }
    if(pal1[i]==pal2[i])
        cout<<"\nAs palavras são iguais!\n";
}
