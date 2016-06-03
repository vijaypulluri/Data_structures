//Linked List
#include<stdio.h>
#include<stdlib.h>
struct SLList{
int data;
struct SLList* next;
};
void print_list(struct SLList *trav)
{
	if(trav == NULL)
	{
		printf("\n -------LIST IS EMPTY-------\n");
		return;
	}
	printf("\n-->LIST is ");
	while(trav!=NULL)
	{
		printf("%d ",trav->data);
		trav =trav->next;
	}
	printf("\n");
}
void insert_at_beg(struct SLList** head_ref,int data)
{
	struct SLList *temp = (struct SLList* )malloc(sizeof(struct SLList));
	temp->data = data;
	temp->next = (*head_ref);
	(*head_ref)=temp;
	printf("\nInserting %d at beginning of LIST",data);
	print_list(*head_ref);
}
void insert_at_end(struct SLList** head_ref,int data)
{
	struct SLList *temp = (struct SLList* )malloc(sizeof(struct SLList));
	temp->data = data;
	temp->next = NULL;
	struct SLList *traverse = *head_ref;
	if(*head_ref == NULL)
	{
		*head_ref=temp;
		print_list(*head_ref);
		return;
	}
	while(traverse->next!=NULL)
		traverse=traverse->next;
	traverse->next=temp;
	printf("\nInserting %d at end of LIST",data);
	print_list(*head_ref);
}
/*
void merge(int arr[],int left,int mid,int right)
{
	int nl=mid+1-left;
	int nr=right-mid;
	int L[mid+1-left];
	int R[right-mid];
	int n=right-left+1,i,j;
	for(i=0;i<=nl;i++)
		L[i]=arr[left+i];
	for(i=0;i<=nr;i++)
		R[i]=arr[mid+1+i];
	i=0;j=0;k=l
	while(i<nl&&j<nr)
	{
		if(L[i]<=R[j])
		{
			arr[k]=L[i];
			i++;
		}
		else
		{
			arr[k]=R[j]
			j++;
		}
		k++;		
	}
	while(i<nl)
	{
		a[k]=R[i];
		i++;
		k++;
	}
	while(j<nr)
	{
		a[k]=R[j];
		j++;
		k++;
	}
	
}

void merge_sort(int arr[],int left,int right)
{
	if(left<right)
	{
		int m=(left+right)/2
		merge_sort(arr[],left,mid);
		merge_sort(arr[],mid+1,right);
		merge(arr[],left,mid,right);
	}
}
*/
void FrontBackSplit(struct SLList *head,struct SLList **left,struct SLList **right)
{
	if(head==NULL||head->next==NULL)
		return;
	struct SLList *slow;
	struct SLList *fast;
	slow=head;
	fast=head->next;
	while(fast!=NULL)
	{
		fast=fast->next;
		if(fast!=NULL)
		{
			slow=slow->next;
			fast=fast->next;
		}
	}
	*left=head;
	*right=slow->next;
	slow->next=NULL;	
}
struct SLList* merge(struct SLList* a,struct SLList* b)
{
	struct SLList* result = NULL;
	if(a==NULL)
		return b;
	if(b==NULL)
		return a;
	if(a->data <= b->data)
	{
		result =a;
		result->next = merge(a->next,b);
	}
	else
	{
		result =b;
		result->next = merge(a,b->next);
	}
	return result;
}

void sort_list_using_Merge_sort(struct SLList **head_ref)
{
	struct SLList *head=*head_ref;
	struct SLList *a;
	struct SLList *b;
	if((head==NULL)||(head->next==NULL))
		return;
	FrontBackSplit(head, &a, &b);
	sort_list_using_Merge_sort(&a);
	sort_list_using_Merge_sort(&b);
	*head_ref = merge(a,b);
}

int main()
{
	int arr[] ={10,2,65,32,12,86,42,7};
	int size=sizeof(arr)/sizeof(arr[0]);
	struct SLList *HEAD=NULL; 
	while(size)
	{
		insert_at_beg(&HEAD,arr[size-1]);
		--size;
	}
	sort_list_using_Merge_sort(&HEAD);
	printf("\n\n*******LIST AFTER SORTING IS********");
	print_list(HEAD);
	
}