//Selection Sort 
/*
Find the minimum element in the unsorted array and swap it with element at begining
Time complexity: O(N^2)
*/
#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the number of elements\n";
    cin>>n;
    
    int a[n];
   for(int i=0;i<n;i++)
    {
        cin>>a[i];
    } 
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++){
            if(a[i]<a[j]){
            int temp=a[j];
            a[j]=a[i];
            a[i]=temp;
        }
        }
    }
     for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}

