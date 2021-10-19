#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int test;
    cin>>test;
    for(int i=0; i<test; i++){
        string s;
        cin>>s;
        if(s.length()<=10){
            cout<<s<<"\n";
        }
        else{
            cout<<s[0]<<s.length()-2<<s[s.length()-1]<<"\n";
        }
    }
    return 0;
}