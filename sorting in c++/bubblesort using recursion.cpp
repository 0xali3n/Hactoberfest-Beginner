#include <iostream>
using namespace std;
void bubblesort(int *arr,int n){
    if(n==0,n==1){
        return;
    }
    else{
        for(int i=0;i<n;i++){
            if(arr[i]>arr[i+1]){
                swap(arr[i],arr[i+1]);
            }
        }
    }
    bubblesort(arr,n-1);
}

int main(){
    int arr[6]={1,5,3,10,4,2};
    bubblesort(arr,6);
    for(int i=0;i<6;i++){
        cout<<arr[i]<<" ";
    }
}
