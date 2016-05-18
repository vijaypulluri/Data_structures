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
void sort_list_using_selection(struct SLList *head )
{
	
	struct SLList *i=head;
	struct SLList *j;
	int temp;
	for(;i->next!=NULL;i=i->next)
	{
		
		for(j=i->next;j!=NULL;j=j->next)
		{
			
			if(i->data > j->data)
			{
				   temp = i->data;
				i->data = j->data;
				j->data = temp;
			}
		}
		print_list(head);
	}
	
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
	sort_list_using_selection(HEAD);
	printf("\n\n*******LIST AFTER SORTING IS********");
	print_list(HEAD);
	
}