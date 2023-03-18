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

    for(int i=0;i<n1;i++){
        int current=arr[i];
        int j=i-1;
        while(arr[j]>current && j>=0){
            swap(arr[j+1],arr[j]);
            j--;
        }


         for(int i=0;i<n1;i++){
        cout<<arr[i]<<" ";

    }
     cout<<endl;
    }


}
