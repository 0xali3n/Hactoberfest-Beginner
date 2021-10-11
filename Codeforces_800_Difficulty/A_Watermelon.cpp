#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int num;
    cin>>num;
    if(num%2!=0 || num<4){
        cout<<"NO\n";
    }
    else{
        cout<<"YES\n";
    }
    return 0;
}