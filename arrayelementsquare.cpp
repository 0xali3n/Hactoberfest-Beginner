#include<iostream>
using namespace std;
void squareofarray(int *p,int n)
{
    *p=(*p)*(*p);
    if(n>0)
    {
        p++;
        squareofarray(p,n-1);
    }

}
int main()
{
    int a[50];
    int num;
    cout<<"Enter the size of an array : "<<endl;
    cin>>num;
    cout<<"enter the numbers of an array:"<<endl;
    for(int i=0;i<num;i++)
    {
        cin>>a[i];
    }
    squareofarray(&a[0],num);
    cout<<endl<<"Square of elements of given array is: "<<endl;
     for(int i=0;i<num;i++)
    {
        cout<<a[i]<<endl;
    }

}
