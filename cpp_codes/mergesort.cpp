//program for merge sort
#include <iostream>
#define MAX 10
using namespace std;
void merge(int arr[], int l, int m, int r)
{
	int n1 = m - l + 1;
	int n2 = r - m;
	int L[n1], R[n2];

	// Copy data to temp arrays L[] and R[]
	for (int i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (int j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	// Merge the temp arrays back into arr[l..r]
	int i = 0;
	int j = 0;

	// Initial index of merged subarray
	int k = l;

	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}
	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}

void mergeSort(int arr[],int l,int r){
	if(l>=r){
		return;//returns recursively
	}
	int m =l+ (r-l)/2;
	mergeSort(arr,l,m);
	mergeSort(arr,m+1,r);
	merge(arr,l,m,r);
}

void printArray(int A[], int size)
{
	for (int i = 0; i < size; i++)
		cout << A[i] << " ";
}
void print_opt(int t[][MAX],int m,int n)
{
	cout<<"\n-----Programe stored on tapes-------\n";
	for(int i=0;i<m;i++)
	{
		for(int j=0;t[i][j]!=0;j++)
		{	
			{		
				cout<<t[i][j]<<"\t";
			}
		}
		cout<<"\n";
	}

	cout<<"\n--------MRT of each tape--------\n";
	int k=1 ,s=0,j=0;
	float sum[m],sm=0.0;
	for(int i=0;i<MAX;i++)
		sum[i]=0;
	for(int i=0;i<m;++i)
	{
		sm=0,j=0;
		while(t[i][j]!=0)
		{
			sm+=t[i][j++];	
		}
		cout<<"MRT of tape "<<i<<"("<<sm<<"/"<<j<<")="<<sm/j<<endl;
		sum[s++]=sm/j;
	}

	float total=0;
	for(int i=0;i<m;i++)
	{
		total+=sum[i];
	}

	cout<<"\n Total MRT is ("<<total<<" /"<<m<<")="<<total/m<<endl;
}

void opt_storage(int arr[],int n,int m)
{
 	 int mat[MAX][MAX];
	for(int i=0;i<MAX;i++)
	{
		for(int j=0;j<MAX;j++)
		{
			mat[i][j]=0;
		}
	}
	int i=0,j=0,k=0;
	while(i<n)
	{
		if(j<m)
		{
			mat[j][k]=arr[i];
			i++;
			j++;
		}
		else
		{
			k++;
			j=0;
		}
		
	}
	print_opt(mat,m,n);
}
int main()
{
	int arr[20],tapes;
	int arr_size;
	cout<<"Enter the number of programs : ";
	cin>>arr_size;
	cout<<"Enter size of each program : ";
	for(int i=0;i<arr_size;i++)
		cin>>arr[i];
	cout<<"Enter number of tapes : ";
	cin>>tapes;
	//cout << "Given array is \n";
	//printArray(arr, arr_size);
	mergeSort(arr, 0, arr_size - 1);
	//cout << "\nSorted array is \n";
	//printArray(arr, arr_size);
	opt_storage(arr,arr_size,tapes);
	return 0;
}

// This code is contributed by Samiksha Hanchate

