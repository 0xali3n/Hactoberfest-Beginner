#include<iostream>
#include<vector>
using namespace std ;

void computeNumber(vector<int> v , int k)
{
    int sum=0 ;
    pair<int ,int> p ;
    for(int i =0 ; i<k ; i++)
    {
        sum+=v[i] ;
    }
    bool found =false ;
    if(sum%3==0)
    {
        p={0,k-1} ;
        found =true ;
    }
    for(int j =k ;j<v.size() ;j++)
    {
        if(found)
        {
            break ;
        }
        sum=sum+v[j]-v[j-k] ;
        if(sum%3==0)
        {
            p={j-k+1 ,j} ;
            found=true ;
        }
    }
    if(!found)
    {
        cout<<"Can Not Make Number Divisible By 3"<<endl ;
    }else{
    for(int i =p.first ; i<=p.second ;i++)
    {
        cout<<v[i]<<" " ;
    }cout<<endl ;
    }
}

int main()
{
    vector<int> v={84,23,45,12,56,82} ;
    int k =3 ;
    computeNumber(v,k) ;
}