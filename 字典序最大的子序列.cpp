#include<iostream>
using namespace std;

int main()
{
    string str;
    while(cin >> str){
        for(int i = str.length() - 1; i >= 1; --i){
            if(str[i-1] < str[i]){
                 str.erase(i-1, 1);
            }
        }
        cout << str;
    }
    return 0;
}
