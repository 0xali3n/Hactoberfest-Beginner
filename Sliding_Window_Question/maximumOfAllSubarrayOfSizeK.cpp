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
    int i =0,j=0 ;
    list<int> l ;
    vector<int> v ;
    while(j<n)
    {
        while(l.size()>0 && l.back()<a[j])
        {
            l.pop_back() ;
        }
        l.push_back(a[j]) ;
        if(j-i+1<k)
        {
            j++ ;
        }
        else
        {
            v.push_back(l.front()) ;
            if(a[i]==l.front())
            {
                l.pop_front() ;
            }
            i++ ;
            j++ ;
        }
    }
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<" " ;
    }
    
    
}