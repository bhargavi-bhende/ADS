#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct node
{
 int data;
 struct node *next;
};

struct node *head=NULL;
int i;

void insert();
void del();
void dis();

int main()
{
 int ch;
 do
 {
 printf("\n1.Insert \n2.Delete \n3.Display \n4.Quit");
 printf("\nEnter your choice : ");
 scanf("%d",&ch);
 switch(ch)
 {
  case 1 : insert();
           break;

  case 2 : del();
           break;

  case 3 : dis();
           break;

  case 4 : exit(1);
 }}while(ch!=4);
 return 0;
}

void insert()
{
 struct node *newnode,*temp;
 int value,op,position;
 printf("\n\t1.Begining \n\t2.Middle \n\t3.End");
 printf("\nEnter your choice : ");
 scanf("%d",&op);
 printf("\nEnter the value to insert : ");
 scanf("%d",&value);
 newnode = malloc(sizeof(struct node));
 newnode->data = value;
 switch(op)
 {
  case 1 : newnode->next = head;
           head = newnode;
           break;

  case 2 : printf("\nEnter position to insert : ");
           scanf("%d",&position);
           temp = head;
           for(i=2; i < position; i++)
           {
            if(temp->next != NULL)
            {
             temp = temp->next;
            }
           }
           newnode->next = temp->next;
           temp->next = newnode;
           break;

  case 3 : newnode->next = NULL;
           temp = head;
           while(temp->next != NULL)
           {
            temp = temp->next;
           }
           temp->next = newnode;
           break;
 }
}

void del()
{
 struct node *temp;
 int position,op;
 printf("\n\t1.Begining \n\t2.Middle \n\t3.End");
 printf("\nEnter your choice : ");
 scanf("%d",&op);
 switch(op)
 {
  case 1 : head = head->next;
           break;

  case 2 : printf("\nEnter position to insert : ");
           scanf("%d",&position);
           for(i=2; i< position; i++)
           {
            if(temp->next!=NULL)
            {
             temp = temp->next;
            }
           }
           temp->next = temp->next->next;
           break;

  case 3 : temp = head;
           while(temp->next->next!=NULL)
           {
            temp = temp->next;
           }
           temp->next = NULL;
           break;
 }
}

void dis()
{
 struct node *temp;
 temp = head;
 printf("\n\nList elements are - \n");
 while(temp != NULL)
 {
  printf("%d --->",temp->data);
  temp = temp->next;
 }
}
