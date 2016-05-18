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
		printf("%d -> ",trav->data);
		trav =trav->next;
	}
	printf("NULL\n");
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
void sort_list_using_Insertion(struct SLList *head )
{
	
	int key;
	if(head==NULL||head->next==NULL)
		return;
	sort_list_using_Insertion(head->next);
	struct SLList *j=head;
	key = j->data;
	while(j->next!=NULL && j->next->data < key)
	{
		j->data = j->next->data;
		j=j->next;
	}
	j->data =key;
		
	/*
	for(i=temp->next;i!=NULL;i=i->next)
	{
		j=i-1;
		key = arr[i];
		while(j>=0 && j > key)
		{
			arr[j+1]=arr[j];
			--j;
		}
		arr[j+1]=key;
	}
	*/
	
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
	sort_list_using_Insertion(HEAD);
	printf("\n\n*******LIST AFTER SORTING IS********");
	print_list(HEAD);
	
}