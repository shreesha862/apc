#ifndef APC_H
#define APC_H

// Node structure for doubly linked list
typedef struct node
{
    int data;  // digit stored in this node
    struct node*prev;  // pointer to previous node
    struct node*nxt; // pointer to next node
}n;


// Function prototypes for linked list operations and arithmetic
void insertlast(n**head,n**tail,int data);  // insert node at end
void insertfirst(n**head,n**tail,int data);  // insert node at beginning
void printlist(n*head);  // print all digits in list
void addnumber(n *head1, n *tail1, n *head2, n *tail2, n **headR, n **tailR);  // add two numbers
int list_compare(n *list1, n *list2);  // compare two lists
void subnumber(n *head1, n *tail1, n *head2, n *tail2,n **headR, n **tailR); // subtract two numbers
void mulnumber(n *head1, n *tail1, n *head2, n *tail2,n **headR, n **tailR);  // multiply two numbers
int deletelist(  n**headR, n**tailR);  // free memory of a list
void divnumber(n *head1, n *tail1, n *head2, n *tail2,n **headQ, n **tailQ, n **headRem, n **tailRem);  // divide list1 by list2

#endif