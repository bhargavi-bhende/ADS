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

int main()
{
 int n,value;
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
 printf("Updated binary tree (Preorder) : ");
 preorder(root);
 return 0;
}
