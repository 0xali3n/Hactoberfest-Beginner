#include<iostream>
using namespace std ;
int main()
{
    int n ;
    cin>>n ;
    int a[n] ;
    for (int i = 0; i < n; i++)
    {
        cin>>a[i] ;
    }
    int k ;
    cin>>k ;
    int i =0,j=0,s=0,ms=INT_MIN ;
    while(j<n)
    {
        s=s+a[j] ;
        if(j-i+1<k)
        {
            j++ ;
        }else if(j-i+1==k)
        {
            ms=max(ms,s) ;
            s=s-a[i] ;
            i++ ;
            j++ ;
        }
    }
    cout<<ms<<endl ;
    
}