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
    int i =0 ,j=0 ;
    int sum =0 ,mx =0 ;
    while(j<n)
    {
        sum=sum+a[j] ;
        if(sum<k)
        {
            j++ ;
        }else if(sum==k)
        {
            mx=max(mx,j-i+1) ;
            j++ ;
        }else if(sum>k)
        {
            while(sum>k)
            {
                sum=sum-a[i] ;
                i++ ;
            }
            j++ ;
        }
    }
    cout<<mx<<endl ;
    
}