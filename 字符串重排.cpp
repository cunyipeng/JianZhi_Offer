#include <iostream>
using namespace std;

int main()
{
    string str;
    cin>>str;
    char map[256] = {0};
    int max = 0;

    for(char c:str){
        map[c]++;
        if(map[c]>max)
            max = map[c];
    }
    for(int i=0; i<max; i++)
    {
        for(int j=0; j<=255; j++)
        {
            if(map[j])
            {
                cout<<(char)j;
                map[j]--;
            }
        }
    }
    return 0;
}
