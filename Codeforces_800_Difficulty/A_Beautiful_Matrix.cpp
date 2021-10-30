#include <bits/stdc++.h>
using namespace std;

int main(){
    int arr[5][5],z,r,c;
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            int a;
            cin>>a;
            arr[i][j]=a;
            if(a==1){
                r=i+1;
                c=j+1;
            }
        }
    }
    int moves=abs(r-3)+abs(c-3);
    cout<<moves<<"\n";
    return 0;
}