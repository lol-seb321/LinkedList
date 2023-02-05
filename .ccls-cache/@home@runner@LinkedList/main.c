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
node* DelList(node *head, int item)
{
  // checks if the head of the list is NULL and if it is, it returns the head.
  // if head is NULL we dont have any LL so we cannot delete a node that doesn't exist
  if(head==NULL)
    return head;

  // If the head is not NULL, the function checks to see if the data in the head is equal to the item passed in
  if(head->data == item)
  {
    // If the data is equal to the item, a temp pointer is created to store the head and the head is set to the         next node in the list. The temp pointer is then freed and the head is returned.
    node* temp = head;
    head = head->next;
    free(temp);
    return head;
  }
  else
  {
    // If the head node's data is not equal to the item, a walker node is created to traverse the list.
    node* walker = head;

    // The walker node moves to the next node until it finds the node with data equal to the item to be deleted or      the end of the list is reached.
    while(walker->next && walker->next->data != item)
      walker = walker->next;

    // If the walker node's next pointer is null, the item is not in the list, and the head node is returned.
    if(!walker->next)
      return head;

    // If the walker node's next node has the data equal to the item, it is deleted and the walker node's next          pointer is updated to point to the node after the deleted node.
    node* temp;
    temp = walker->next;
    walker->next = walker->next->next;
    free(temp);
  }
  return head;  
}

/* This function is inserting an item into a sorted linked list (LL). The linked list is represented by a root node (head), and each node has a data and a next field. The function returns the root node of the linked list after the insertion.
*/
node* insert_sorted(node* root, int item)
{
  /*
  A new node is created using malloc and its data field is set to the item passed as an argument.
  The next field of the new node is set to NULL, so we can keep making new nodes.
  */
  node *temp = malloc(sizeof(node));
  temp->data = item;
  temp->next = NULL;

  /*
  The function checks if the linked list is empty '(root == NULL)' or if the item being inserted is smaller than      the data of the root node '(item < root->data).'
  */
  // check do we have a LL at all or is it smallest number in LL
  if(root == NULL || item < root->data)
  {
    /*
    If either of these conditions are true, the new node is inserted at the beginning of the linked list by             updating its next field to the current root and setting the root to the new node.
    */
    temp->next = root;
    root = temp; 
  }
  else
  {
    /*
    If neither condition is true, the function uses a walker node to traverse the linked list. The walker node          starts at the root.
    */
    node* walker = root; // traverse our LL

    // The while loop continues as long as the walker node has a next node and the data of the next node is less        than the item being inserted(we want to insert after so we can sort our LL). The walker node is updated to its      next node each iteration.
    // we go to the next node by setting walker to next
    while(walker->next && item > walker->next->data)
      walker = walker->next; // The walker node is updated to its next node each iteration.

    // When the while loop terminates, the next field of the new node is set to the next field of the current           walker node, and the next field of the walker node is set to the new node.
    temp->next = walker->next;
    walker->next = temp;
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
printf("\nMenu: 1. insert at front, 2. insert at end, 3. Delete 4. exit:  5. Sorted LL ");
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
  if(ch==5)
  {
    printf("\nEnter data(int): ");
    scanf("%d", &ele);

    root = insert_sorted(root, ele);

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