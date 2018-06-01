#include<iostream>
using namespace std;

int main()
{
    int N,n;
    while(cin>>N){
       int book[1001] = {0};
       while(N--){
           cin>>n;
           book[n] = 1;
       }
       for(int i = 0; i<1001; i++)
            if(book[i])
               cout<<i<<endl;
    }
    return 0;
}
