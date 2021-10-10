#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,k,count=0;
    cin>>n>>k;
    vector<int> v;
    for(int i=0; i<n; i++){
        int a;
        cin>>a;
        v.push_back(a);
    }
    int z=v[k-1];
    for(int i=0; i<n; i++){
        if(v[i]>=z && v[i]!=0){
            count++;
        }
        else{
            break;
        }
    }
    cout<<count<<"\n";
    return 0;
}