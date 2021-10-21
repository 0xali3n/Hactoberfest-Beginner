#include"bits/stdc++.h"
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
    list<int> l ;
    
    int i =0,j=0 ;
    while(j<n)
    {
        if(a[j]<0)
        {
            l.push_back(a[j]) ;
        }
        if(j-i+1<k)
        {
            j++ ;
        }else if(j-i+1==k)
        {
            if(l.empty())
            {
                cout<<0<<" " ;
            }else 
            {
                cout<<l.front()<<" " ;
            }
            if(a[i]==l.front())
            {
                l.pop_front() ;
            }
            i++ ;
            j++ ;
        }
    }
    
}