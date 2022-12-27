#include<stdio.h>
#include<stdlib.h>

struct node
{
 int data;
 struct node *left;
 struct node *right;
};

struct node* insert(struct node *root,int value)
{
 if(root==NULL)
  {
   root=malloc(sizeof(struct node));
   root->data = value;
   root->left = NULL;
   root->right = NULL;
  }
 else if(value < root->data)
  {
   root->left = insert(root->left,value);
  }
 else if(value > root->data)
  {
   root->right = insert(root->right,value);
  }
  return root;
}

void preorder(struct node *root)
{
 if(root == NULL)
 {
  return;
 }
 printf(" %d",root->data);
 preorder(root->left);
 preorder(root->right);
}

void inorder(struct node *root)
{
 if(root == NULL)
 {
  return;
 }
 inorder(root->left);
 printf(" %d",root->data);
 inorder(root->right);
}

void postorder(struct node *root)
{
 if(root == NULL)
 {
  return;
 }
 postorder(root->left);
 postorder(root->right);
 printf(" %d",root->data);
}

int main()
{
 int n,value,ch;
 struct node *root = NULL;
 printf("Enter number of nodes to be inserted : ");
 scanf("%d",&n);
 printf("Enter the value of the nodes to be inserted : ");
 while(n>0)
 {
 scanf("%d",&value);
 root = insert(root,value);
 n--;
 }
 printf("\nRepresentation : \n\t1.Preorder \n\t2.Inorder \n\t3.Postorder");
 printf("\nEnter your choice : ");
 scanf("%d",&ch);
 switch(ch)
 {
  case 1 : preorder(root);
           break;

  case 2 : inorder(root);
           break;

  case 3 : postorder(root);
           break;

  default : printf("Wrong choice!");
 }
 return 0;
}
