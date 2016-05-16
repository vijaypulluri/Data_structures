#include<stdio.h>
int heapsize=-1;
int heap[100];

void printheap()
{
	int i;
	if(heapsize<0)
	{
		printf("\n***********Heap is Empty*******\n");
		return;
	}
	for(i=0;i<=heapsize;i++)
		printf("%d ",heap[i]);
	printf("\n");
}
void printheap_2()
{
	int i;
	printf("\t\t");
	for(i=0;i<=13;i++)
		printf("%d ",heap[i]);
	printf("\n");
}
void swap(int *a , int *b)
{
	int t;
	t=*a;
	*a=*b;
	*b=t;
}
void heapify(int i,int size)
{
	int left,right,largest=i;
	left=2*i+1;
	right=2*i+2;
//	printf("\nleft=%d, Right =%d\n",left,right);
	if(left<=size && heap[left]>heap[i])
		largest=left;
	if(right<=size && heap[right]>heap[largest])
		largest=right;
	//printf("\n****largest = %d*******i = %d ******\n",largest,i);
	if(largest!=i)
	{
		swap(&heap[i],&heap[largest]);		
		heapify(largest,size);
	}
	
}
void insert_to_heap(int data)
{
	++heapsize;
	int parent=(heapsize-1)/2;
	int i;
	heap[heapsize]=data;
	if(heapsize>0)
	{	
		for(i=parent;i>=0;i--)
			heapify(i,heapsize);	
	}
}
void sort_heap()
{
	int i;
	for(i=heapsize;i>=0;i--)
	{
		swap(&heap[0],&heap[i]);
		heapify(0,i-1);
	}
	printf("\nSorted heap is.....\n");
	printheap();
}
void delete_max()
{
	if(heapsize==-1){
		printf("\nHEAP IS EMPTY\n");
		return;
	}
	printf("Removed max i.e = %d\n",heap[0]);
	heap[0]=heap[heapsize];
	heap[heapsize]=0;
	--heapsize;
//	printf("\nheapsize %d\n",heapsize);
	heapify(0,heapsize);
	printf("New Heap is....\n");
	printheap();

}
int main()
{
	int arr[]={2,32,43,63,12,5,37,65,84};
	int n=sizeof(arr)/sizeof(arr[0]);
	int i;
	for(i=0;i<n;i++)
	{
	//	printf("\tcall ====== %d\n",i+1);
		insert_to_heap(arr[i]);
	}
	printheap();
	//	sort_heap();
	delete_max();
	delete_max();

}