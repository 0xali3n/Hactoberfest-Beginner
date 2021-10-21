#include "bits/stdc++.h"
using namespace std ;

int maxSubarraySum(int a[] ,int n ,int k)
{
    int j =0 ,i =0,s=0,ms =0 ;
    while(j<n)
    {
        s=s+a[j] ;
        if(j-i+1<k)
        {
            j++ ;
        }else if (j-i+1==k)
        {
            ms=max(ms,s) ;
            j++ ;
            s=s-a[i] ;
            i++ ;
        }
    }
    return ms ;
}

void firstNegativeIntegerOfEveryWindow(int a[] ,int n, int k)
{
    vector<int> v ;
    list<int> l;
    int i =0 ,j=0 ;
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

void maximumOfAllSubarrayOfEveryWindow(int a[] ,int n ,int k)
{
    int i =0,j=0 ;
    list<int> l ;
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
        }else
        {
            cout<<l.front()<<" " ;
            if(a[i]==l.front())
            {
                l.pop_front() ;
            }
            i++ ;
            j++ ;
        }
    }
}

int largestSubarrayOfSumk(int a[] ,int n ,int k)
{
    int i =0,j=0,s=0,c=0 ;
    while(j<n)
    {
        s=s+a[j] ;
        if(s<k)
        {
            j++ ;
        }else if(s==k)
        {
            c=max(c,j-i+1) ;
            s=s-a[i] ;
            i++ ;
            j++ ;
        }else if(s>k)
        {
            while(s>k)
            {
                s=s-a[i] ;
                i++ ;
            }

            j++ ;
        }
    }
    return c ;
}

int maxSubarraySumSizekSumlessThnX(int a[] ,int n ,int k ,int x)
{
    int i =0,j=0 ,s=0 ,mx=0;
    while(j<n)
    {
        s=s+a[j] ;
        if(j-i+1<k)
        {
            j++ ;
        }else if (j-i+1==k)
        {
            if(s<x)
            {
                mx=max(mx,s) ;
            }
            s=s-a[i] ;
            i++ ;
            j++ ;
        }
    }
    return mx ;
}

void fromNumberDivisibleBy3(int a[] ,int n ,int k)
{
    int i =0 ,j=0 ,s=0 ;
    for(int j =0 ;j<k ;j++)
    {
        s=s+a[j] ;
    }
    if(s%3==0)
    {
        cout<<"Yes"<<endl ;
        return ;
    }
    for (int j = k; j < n; j++)
    {
       s=s+a[j] ;
       s=s-a[i] ;
       i++ ;
       if(s%3==0)
       {
           cout<<"Yes"<<" " ;
           return ;
       } 
    }
    
}

bool isPalindrome(int n)
{
    int temp =n ;
    int s =0 ;
    while(n>0)
    {
        int r =n%10 ;
        s=s*10+r ;
        n=n/10 ;
    }
    return (temp==s) ;
}

int subarrayWithPalindromicConct(int a[] ,int n ,int k)
{
    int s=0 ;
    for(int j =0 ;j<k ;j++)
    {
        s=s*10+a[j] ;
    }
    if(isPalindrome(s))
    {
        return 0 ;
    }
    for(int j =k ; j<n ; j++)
    {
        s=(s% (int)pow(10,k-1))*10 + a[j] ;
        if(isPalindrome(s))
        {
            return j-k+1 ;
        }
    }
    return -1 ;
}

int main()
{
    //415545514
    int a[] ={1,4,4,2,4,3,1} ;
    int k =3 ;
    int i =subarrayWithPalindromicConct(a,7,k) ;
    if(i>=0)
    {
        for (int j = i; j < i+k; j++)
        {
            cout<<a[j]<<" " ;
        }
        
    }
}