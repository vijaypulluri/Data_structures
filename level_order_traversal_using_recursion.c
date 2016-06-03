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
void printgivenlevel(struct node *root,int level)
{
	if(root==NULL)
		return;
	if(level==1)
		printf("%d ",root->data);
	else if(level>1)
	{
		printgivenlevel(root->left,level-1);
		printgivenlevel(root->right,level-1);
	}
}
void printlevelorder(struct node *root)
{
	int i,h =height(root);
	for(i=0;i<=h;i++)
		printgivenlevel(root,i);
}

int main()
{
	struct node *root=newnode(1);
	root->left = newnode(2);
	root->right = newnode(3);
	root->left->left = newnode(4);
	root->left->right = newnode(5);
	printf("\n LEVEL ORDER is --> ");
	printlevelorder(root);
	printf("\n\n");
}