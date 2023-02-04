/* Tanvir Ahmed
This code implements some basic operation of singly linked list like inserting in 
the beginning and end, delete operation, and display operation
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
  int data;
  struct node *next;
}node;

//this function takes an item and insert it in the linked list pointed by root.
node*  insert_front(node *root, int item)
{
  // create a node
  node* temp = malloc(sizeof(node));
  temp->data = item;
  temp->next = NULL;

  // this means our linked list is empty
  if(root == NULL)
  {
    root = temp;
    return root;
  }
  else
  {
    temp->next = root;
    root = temp;
    return root;
  }

}

//this function takes an item and insert it in the end of the linked list
node* insert_end(node* root, int item)
{
  node *t;
  node* temp = malloc(sizeof(node));
  temp->data = item;
  temp->next = NULL;

  if(root == NULL)
  {
    root = temp;
    return root;
  }
  else
  {
    node* t = root;
    while(t->next != NULL)
      t = t->next;

    t->next = temp;
    return root;
  }
}

/*this function deletes the first occurrence of a given item from linked list.
it returns the updated/original root
*/
node* DelList(node *root, int item)
{




  
}

node* insert_sorted(node* root, int item)
{
  node *temp = malloc(sizeof(node));
  temp->data = item;
  temp->next = NULL;

  // check do we have a LL at all or is it smallest number in LL
  if(root == NULL || item < root->data)
  {
    temp->next = root;
    root = temp; 
  }
  else
  {
    node* walker = root; // traverse our LL
    if(walker->next != NULL && walker->next->data > item)
    {
      
    }
    else
    {
      walker = walker->next;
    }
  }
    
  return root;
}

// prints entire linked list
void display(node* t)
{
  printf("\nPrinting your linked list.......");
while(t!=NULL)
{
printf("%d ",t->data);
t=t->next;
}
}


int main()
{
// this is our head
node *root = NULL; //very important line. Otherwise all function will fail
  
node *t; // to traverse a linked list
int ch,ele,v, del;

  
while(1)
{
printf("\nMenu: 1. insert at front, 2. insert at end, 3. Delete 4. exit: ");
    scanf("%d",&ch);
if(ch==4)
{
printf("\nGOOD BYE>>>>\n");
break;
}
if(ch==1)
{
printf("\nEnter data(an integer): ");
scanf("%d",&ele);
root = insert_front(root, ele);
      display(root);
}
if(ch==2)
{
printf("\nEnter information(an integer): ");
scanf("%d",&ele);
root = insert_end(root, ele);
      display(root);
}
  if(ch==3)
  {
  printf("\nEnter info which u want to DELETE: ");
  scanf("%d",&del);
  root=DelList(root, del);
      display(root);
}
}
  return 0;
}




/*
  #include <stdio.h>

// defining a node
typedef struct node
{
int info; // holds data you want to store
struct node *next; // a link which is a pointer. Known as next. It can point to next node
}node;

// node example with more than one field
struct Book_node
{
char name[20];
char authors[8];
int year;
struct Book_node *next; // struct pointer that can point to next node
};

struct Book{
char name[20];
char author[8];
int year;
};

struct Book_node_seperate
{
struct Book info;
struct Book_node_seperate *next; // book node type of pointer
};

int main(void) {
  printf("Hello World\n");
  return 0;
}
*/