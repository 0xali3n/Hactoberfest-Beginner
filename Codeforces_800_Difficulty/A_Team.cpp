#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,count=0;
    cin>>n;
    vector<int> v(3,0);
    for(int i=0; i<n; i++){
        int sum=0;
        for(int j=0; j<3; j++){
            int a;
            cin>>a;
            sum+=a;
        }
        if(sum>1){
            count++;
        }
    }
    cout<<count<<"\n";

    return 0;
}