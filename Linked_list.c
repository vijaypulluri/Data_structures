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
void insert_at_pos(struct SLList** head_ref,int data, int pos)
{
	struct SLList *temp = (struct SLList* )malloc(sizeof(struct SLList));
	temp->data = data;
	struct SLList *traverse = *head_ref;
	if(pos<1)
	{
		printf("\n****Invalid position position should be greater than 0 \n");
		return;
	}
	printf("\nInserting %d at position %d of LIST",data,pos);
	if(pos==1)
	{
		temp->next = *head_ref;
		*head_ref=temp;
		print_list(*head_ref);
		return;
	}
	while(pos-2)
	{
		traverse =traverse->next;
		--pos;		
	}
	temp->next = traverse->next;
	traverse->next =temp;
	print_list(*head_ref);
}
void delete_at_beg(struct SLList** head_ref)
{
	struct SLList *temp = *head_ref;
	if(*head_ref == NULL)
	{
		printf("\n List is empty.....\n");
		return ;
	}
	*head_ref=temp->next;
	printf("\nDeleting %d from the list beginning",temp->data);
	free(temp);
	print_list(*head_ref);
}
void delete_at_end(struct SLList** head_ref)
{
	struct SLList *temp = *head_ref;
	struct SLList *temp2;
	if(*head_ref == NULL)
	{
		printf("\nNothing to delete List is already empty.....\n");
		return ;
	}	
	if(temp->next == NULL)
	{
		printf("\nDeleting %d from the list end",temp->data);
		free(temp);
		*head_ref = NULL;
		print_list(*head_ref);
		return ;
	}
	while(temp->next != NULL)
	{
		temp2=temp;
		temp=temp->next;
	}
	temp2->next=NULL;
	printf("\nDeleting %d from the list end",temp->data);
	free(temp);
	print_list(*head_ref);
}
void delete_at_pos(struct SLList** head_ref, int pos)
{
	struct SLList *traverse = *head_ref;
	struct SLList *temp;
	printf("\nDelete %d position of LIST",pos);
	while(pos-2)
	{
		traverse =traverse->next;
		--pos;		
	}
	temp=traverse->next;
	traverse->next=temp->next;
	free(temp);
	print_list(*head_ref);
}
void delete_all(struct SLList** head_ref)
{
	struct SLList *temp;
	while(*head_ref!=NULL)
	{
		temp=*head_ref;
		*head_ref=(*head_ref)->next;
		free(temp);
	}
	printf("\n\nCleared all the memory allocated\n");
	
}
void insert_at_middle(struct SLList *head_ref,int data)
{
	struct SLList *slowptr,*fastptr;
	struct SLList *temp = (struct SLList* )malloc(sizeof(struct SLList));
	temp->data=data;
	slowptr=fastptr=head_ref;
	printf("\nInserting at middle");
	while(fastptr->next != NULL && fastptr->next->next!=NULL)
	{
		slowptr=slowptr->next;
		fastptr=fastptr->next->next;
	}
	temp->next=slowptr->next;
	slowptr->next=temp;
	print_list(head_ref);
}
void print_middle(struct SLList *head_ref)
{
	struct SLList *slowptr,*fastptr;
	slowptr=fastptr=head_ref;
	while(fastptr != NULL && fastptr->next!=NULL)
	{
		slowptr=slowptr->next;
		fastptr=fastptr->next->next;
	}
	printf("\nMiddle_Element is %d\n",slowptr->data);
}

void print_reverse(struct SLList *head_ref)
{
	if(head_ref==NULL)
		return;
	print_reverse(head_ref->next);
	printf("%d ",head_ref->data);
}
void reverse_using_iterative(struct SLList **head_ref)
{
	struct SLList *prev,*current,*nextt;
	prev = NULL;
	current = (*head_ref);
	printf("\n\nAfter Reversing using iterative ");
	while(current!=NULL)
	{
		nextt=current->next;
		current->next = prev;
		prev = current;
		current = nextt;
	}
	(*head_ref) = prev;
	print_list(prev);
}
void reverse_using_recursion(struct SLList *temp, struct SLList **head_ref)
{
	if(temp->next == NULL)
	{
		*head_ref = temp;
		return;
	}
	reverse_using_recursion(temp->next,head_ref);
	struct SLList *temp2 = temp->next;
	temp2->next=temp;
	temp->next = NULL;
}
int main()
{
	/*  Functions defined
		1.)print_list 		2.)print_middle 	3.)print_reverse
		2.)delete_at_beg 	3.)delete_at_end 	4.)delete_at_pos	5.)delete_all
		5.)insert_at_beg 	6.)insert_at_end 	7.)insert_at_middle	   8.)insert_at_pos	
	   11.)reverse_using_iterative 		12.)reverse_using_recursion
	*/
	struct SLList *HEAD=NULL;
	print_list(HEAD);
	delete_at_beg(&HEAD);
	delete_at_end(&HEAD);
	insert_at_beg(&HEAD,20);
	insert_at_beg(&HEAD,25);
	delete_at_end(&HEAD);
	insert_at_beg(&HEAD,33);
	delete_at_beg(&HEAD);
	insert_at_end(&HEAD,44);
	insert_at_end(&HEAD,65);
	delete_at_end(&HEAD);
	delete_at_beg(&HEAD);
	insert_at_beg(&HEAD,31);
	insert_at_beg(&HEAD,39);
	insert_at_beg(&HEAD,34);
	insert_at_beg(&HEAD,54);
	insert_at_pos(&HEAD,75,3);
	delete_at_pos(&HEAD,4);
	print_middle(HEAD);
	insert_at_middle(HEAD,43);
	print_middle(HEAD);
	insert_at_middle(HEAD,49);
	print_middle(HEAD);
	printf("\n Simply printing Reverse is --> ");
	print_reverse(HEAD);
	reverse_using_iterative(&HEAD);
	reverse_using_recursion(HEAD,&HEAD);
	printf("\nList After Reverse is  --> ");
	print_list(HEAD);
	delete_all(&HEAD);
	print_list(HEAD);
	
}