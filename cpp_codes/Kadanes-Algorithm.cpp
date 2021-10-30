#include<iostream>
using namespace std;

//it is used for finding maximum sum contiguous sub-array within a one dimensional numeric array
int maxi(int a,int b){
    if(a>=b){
        return a;
    }
    else if(a<b){
        return b;
    }
    return 0;
}

int maxSubsetSum(int arr[],int size){
    int max = arr[0];
    int current = arr[0];
    
    for(int i=0;i<size;i++){
        current = maxi(arr[i],current+arr[i]);
        max = maxi(max,current);
    }
    return max;
}

int main(){
    int arr[]= {-2,-5,2,-3,3,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    int maxi_sum = maxSubsetSum(arr,n);
    cout<<"Maximum Contiguous Sum is : "<<maxi_sum;
    return 0;

}