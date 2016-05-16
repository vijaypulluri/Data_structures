#include<stdio.h>
void swap(int *a, int *b)
{
	int t=*a;
	*a=*b;
	*b=t;
}

void heapify(int arr[],int size,int i)
{
	int left=2*i+1;
	int right=2*i+2;
	int largest=i;
	if(left<size && arr[left]>arr[i])
		largest = left;
	if(right<size && arr[right]>arr[largest])
		largest = right;
	if(largest != i )
	{
		swap(&arr[i],&arr[largest]);
		heapify(arr,size,largest);
	}
	
}
void heapsort(int arr[],int size)
{
	for(i=size/2-1;i>=0;i--)
		heapify(arr,size,i);
	for(i=size;i>=0;i--)
		heapify(arr,i,0);
}
void print(int arr[] ,int size)
{
	int i=0;
	for(i=0;i<size;i++)
	{	
		printf("%d ",arr[i]);
	}
}
int main()
{
	int arr[]={2,30,21,36,20,64,34,73};
	int size=sizeof(arr)/sizeof(arr[0]);
	heapsort(arr,size);
	print(arr,size);	
}
