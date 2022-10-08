#include <iostream>

using namespace std;

int main()
{
    int n1;
    cin>>n1;
   int arr[n1];
   for(int i=0;i<n1;i++){
       cin>>arr[i];
   }
   cout<<"unsorted list is"<<endl;
    for(int i=0;i<n1;i++){
       cout<<arr[i]<<" ";
   }
   cout<<endl;
   for(int j=0;j<n1-1;j++){
       for(int k=j+1;k<n1;k++){
           if(arr[k]<arr[j]){
               swap(arr[k],arr[j]);
           }
       }

    for(int i=0;i<n1;i++){
       cout<<arr[i]<<" ";
   }
   cout<<endl;
   }

}
