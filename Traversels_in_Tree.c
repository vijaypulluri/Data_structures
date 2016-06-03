#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *left;
	struct node *right;
};
struct node * newnode(int data)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = data;
	temp->left =NULL;
	temp->right =NULL;
	return temp;
}
void printINorder(struct node *root)
{
	if(root == NULL)
		return;
	printINorder(root->left);
	printf("%d ",root->data);
	printINorder(root->right);
}
void printPREorder(struct node *root)
{
	if(root==NULL)
		return;
	printf("%d ",root->data);
	printPREorder(root->left);
	printPREorder(root->right);
}
void printPOSTorder(struct node *root)
{
	if(root==NULL)
		return;
	printPOSTorder(root->left);
	printPOSTorder(root->right);
	printf("%d ",root->data);
}
int height(struct node *root)
{
	if(root == NULL)
		return 0;
	else
	{
		int lheight = height(root->left);
		int rheight = height(root->right);
		if(lheight > rheight)
			return (lheight+1);
		else
			return (rheight+1);
	}
}
int main()
{
	struct node *root=newnode(1);
	root->left = newnode(2);
	root->right = newnode(3);
	root->left->left = newnode(4);
	root->left->right = newnode(5);
	int h = height(root);
	printf("\n Height is --> %d",h);
	printf("\n INORDER IS --> ");
	printINorder(root);
	printf("\n PREORDER IS --> ");
	printPREorder(root);
	printf("\n POSTORDER IS --> ");
	printPOSTorder(root);
	printf("\n\n");
}