#include <bits/stdc++.h>
using namespace std;
int main(){
    int test,add=0,sub=0;
    cin>>test;
    for(int i=0; i<test; i++){
        string s;
        cin>>s;
        if(s[1]=='+'){
            add++;
        }
        else if(s[1]=='-'){
            sub++;
        }
    }
    cout<<add-sub<<"\n";

    return 0;
}