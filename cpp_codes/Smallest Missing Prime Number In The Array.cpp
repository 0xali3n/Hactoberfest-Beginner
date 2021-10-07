//Smallest Missing Prime Number In The Array

#include <iostream>
using namespace std;

int main()
{
    int a[100],size,f,i,j,k,l,p=0,m=1;
    cout<<"Enter size of array : ";
    cin>>size;
    cout<<"Enter the elements of array : ";
    for(i=0;i<size;i++)
    { cin>>a[i]; }
    l=a[0];

    //Loop to store the largest element in l
    for(i=0;i<size;i++)
    { 
        if(l<a[i])
        l=a[i];
    }

    //Loop to find the prime numbers less than or equal to l and search for the smallest missing prime number 
    for(k=2;k<=l;k++)                   
    {   
        f=0;
        m=0;
        for(j=2;j<k;j++)
        {
            if(k%j==0)
            {
                f=1;
                break;
            }
        }
        if(f==0)
        {
            for(i=0;i<size;i++)
            { if(k==a[i])
              {
                  m=1;
                  break;
              }
            }
            if(m==0)
            {
                cout<<endl<<k<<" is the smallest missing prime number from the given array";
                p=1;
            }            
        }
        if(p==1)
        break;
    }
    if(m==1 || p==0)
    cout<<endl<<"No smallest prime number is missing in the given array";

    return 0;
}
