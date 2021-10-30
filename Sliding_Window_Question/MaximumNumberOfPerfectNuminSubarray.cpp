#include"bits/stdc++.h"
using namespace std ;

bool isPerfect(int n)
{
    int s =1 ;
    for(int i =2 ;i<sqrt(n) ;i++)
    {
        if(n%i==0)
        {
            if(i==n/i)
            {
                s=s+i ;
            }else
            {
                s=s+i+n/i ;
            }
        }
    }
    if(s==n && n!=1)
    {
        return true ;
    }
    return false ;
}

int maxSum(int a[] ,int n ,int k)
{
    int i =0,j=0 ,mx=-1,sum=0 ;
    while(j<n)
    {
        sum=sum+a[j] ;
        if(j-i+1<k)
        {
            j++ ;
        }else if(j-i+1==k)
        {
            mx=max(mx,sum) ;
            sum=sum-a[i] ;
            i++ ;
            j++ ;
        }
    }
    return mx ;
}

int maxPerfectNum(int a[] ,int n ,int k)
{
    for (int i = 0; i < n; i++)
    {
        if(isPerfect(a[i]))
        {
            a[i]=1 ;
        }else
        {
            a[i]=0 ;
        }
    }
    return maxSum(a,n,k) ;
    
}

int main()
{
    int a[] ={28,2,3,6,496,99,8128,24} ;
    int k =4 ;
    int n=8 ;
    cout<<maxPerfectNum(a,n,k)<<endl ;
    deque<int> dq ;
    
}