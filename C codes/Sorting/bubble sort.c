#include<stdio.h>
int main()
{
	int a[10],n;
	printf("enter the number of elements\n");
	scanf("%d",&n);
	printf("enter the elements\n");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				int temp;
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
	printf("sorted elements\n");
	for(int i=0;i<n;i++)
	{
		printf("%d\n",a[i]);
	}
	return 0;
}
