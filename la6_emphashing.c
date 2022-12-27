#include<stdio.h>
#include<stdlib.h>
#define n 10

int hash[n],i,key,value;

void ini();
void insert(int);
void del(int);
void sc(int);
void dis();

int main()
{
 int ch;
 ini();
 printf("\nHash Table Size : %d",n);
 do
 {
 printf("\n1.Insert \n2.Delete \n3.Search \n4.Display \n5.Quit");
 printf("\nEnter your choice : ");
 scanf("%d",&ch);
 switch(ch)
 {
  case 1 : printf("\nEnter the value to be inserted : ");
           scanf("%d",&value);
           insert(value);
           break;

  case 2 : printf("\nEnter the value to be deleted : ");
           scanf("%d",&value);
           del(value);
           break;

  case 3 : printf("\nEnter the value to be searched : ");
           scanf("%d",&value);
           sc(value);
           break;

  case 4 : dis();
           printf("\n------------");
           break;

  case 5 : break;

  default : printf("\n Wrong choice");
 }}while(ch!=5);
 return 0;
}

void ini()
{
 for(i=0;i<n;i++)
  hash[i]=-1;
}

void insert(int value)
{
key=value%n;
if(hash[key]==-1)
{
 hash[key]= value;
 printf("\n%d inserted at hash_table[%d]",value,key);
 }
else
 {
  printf("\nDue to colllison at hash_table[%d], %d unable to insert",key,value);
 }
}

void del(int value)
{
 key=value%n;
 if(hash[key]==value)
  {
   hash[key]=-1;
   printf("\n%d deleted from hash_table[%d]",value,key);
  }
  else
  {
   printf("\n%d not present in the hash table",value);
  }
}

void sc(int value)
{
 key=value%n;
 if(hash[key]== value)
  {
   printf("\n%d Employee ID found at hash_table[%d]",value,key);
  }
 else
 {
  printf("\nNo ID found");
 }
}

void dis()
{
 printf("\n");
 for(i=0;i<n;i++)
 {
  printf("\n------------");
  printf("\n %d",hash[i]);
 }
}
