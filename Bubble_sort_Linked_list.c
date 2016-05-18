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

void sort_list_using_Bubble_normal(struct SLList *head ) //Find optimal solution down "sort_list_using_Bubble_optimal"
{
	
	struct SLList *i=NULL;
	struct SLList *j,*temp;
	int temp2,swapped;
	for(i=head;i->next!=NULL;i=i->next)  //for(i=0;i<size-1;i++)
	{
		swapped=0;
		for(j=head;j->next!=temp;j=j->next) //for(j=0;j<size-1-i;j++)
		{
			if(j->data > j->next->data)
			{
				   temp2 = j->data;
				j->data = j->next->data;
				j->next->data = temp2;
				swapped=1;
			}
		}
		temp=j;
		if(swapped==0)
			break;
		print_list(head);
	}
	
}

void sort_list_using_Bubble_optimal(struct SLList *head )
{
	
	struct SLList *i=NULL;
	struct SLList *j;
	int temp,swapped;
	do  //for(i=0;i<size-1;i++)
	{
		swapped=0;
		for(j=head;j->next!=i;j=j->next) //for(j=0;j<size-1-i;j++)
		{
			if(j->data > j->next->data)
			{
				   temp = j->data;
				j->data = j->next->data;
				j->next->data = temp;
				swapped=1;
			}
		}
		i=j;  //Extra for LINKED LIST
		print_list(head);
	}while(swapped);
	
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
	sort_list_using_Bubble_normal(HEAD);
	printf("\n\n*******LIST AFTER SORTING IS********");
	print_list(HEAD);
	
}