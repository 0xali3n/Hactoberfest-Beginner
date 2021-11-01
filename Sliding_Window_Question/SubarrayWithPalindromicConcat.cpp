#include"bits/stdc++.h"
using namespace std ;

bool isPalindrome(int n)
{
    int t =n ,number =0 ;
    while (t>0)
    {
        number = number*10+t%10 ;
        t=t/10 ;
    }
    if(number==n)return true ;
    return false ;
}

int palindromicSubarray(vector<int> v ,int k)
{
    int n=0 ;
    for(int i =0 ; i<k ;i++)
    {
        n=n*10+v[i] ;
    }
    if(isPalindrome(n))
    {
        return 0 ;
    }
    for(int j =k ;j<n ;j++)
    {
        n=(n%(int)pow(10,k-1))*10+v[j] ;
        if(isPalindrome(n))
        {
            return j-k+1 ;
        }
    }
    return -1 ;
}

int main()
{
    vector<int> v ={1,2,3,5,1,1,5} ;
    int k =4 ;
    int ans=palindromicSubarray(v,k) ;
    if(ans !=-1)
    {
        for (int i = ans; i < ans+k; i++)
        {
            cout<<v[i]<<" " ;
        }cout<<endl ;
        
    }
}