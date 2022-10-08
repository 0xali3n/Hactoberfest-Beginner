#include <iostream>

using namespace std;


int partition(int *arr,int s,int e){
    int pivot=arr[s];
    int i=s;
    int j=e;
    while (i<j){
        while(arr[i]<pivot){
            i++;
        }
    while(arr[j]>pivot){
        j--;
    }
    if(i<j){
        swap(arr[i],arr[j]);
    }
    }
    swap(arr[j],pivot);
    return j;
}

void quicksort(int *arr,int s, int e){
    if(s<e){
    int par=partition(arr,s,e);
    quicksort(arr,s,par-1);
    quicksort(arr,par+1,e);}
}

int main()
{
    int arr[5]={1,76,43,4,34};
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
     cout<<endl;
    quicksort(arr,0,5);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }


}

