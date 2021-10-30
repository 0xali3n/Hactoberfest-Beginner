#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int n,k;
    cin>>n>>k;
    
    int count=0;
    while(n>1 && k>count)
    {
        int rem=n%10;
        if(rem==0)
        {
            n=n/10;
        }
        else
        {
            n=n-1;
        }
        count++;
    }
    cout<<n<<endl;
        
}