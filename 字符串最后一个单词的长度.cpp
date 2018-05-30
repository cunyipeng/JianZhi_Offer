#include<iostream>
using namespace std;

int main(){
    string str;
    getline(cin, str);
    int n = str.size();
    for(int i = n - 1; i >= 0; i--) {
        if(str[i] == ' '){
             cout << n - 1 - i << endl;
             break;
         }
         if(i == 0)
             cout << n << endl;
    }
    return 0;
}
