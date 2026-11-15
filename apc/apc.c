#include <stdio.h>
#include <stdlib.h>
#include "apc.h"


// Insert a new node at the end of the list
void insertlast(n **head, n **tail, int data) 
{
    n *new = malloc(sizeof(n));    // allocate memory for new node
    if (new == NULL) 
    {
        printf("No nodes available\n");   // allocation failed
        return;
    }

    new->data = data;    // store digit
    new->nxt = NULL;     // next pointer is NULL

    if (*head == NULL && *tail == NULL)  // empty list case
    {
        new->prev = NULL;  // no previous node
        *head = *tail = new; // head and tail both point to new
    } 
    else 
    {
        new->prev = *tail;  // link back to old tail
        (*tail)->nxt = new;   // old tail points forward to new
        *tail = new;    // update tail to new node
    }
}

// Insert a new node at the beginning of the list
void insertfirst(n **head, n **tail, int data)
 {
    n *new = malloc(sizeof(n));   // allocate memory for new node
    if (new == NULL) 
    {
        printf("No nodes available\n");  // allocation failed
        return;
    }

    new->data = data;   // store digit
    new->prev = NULL;  // no previous node

    if (*head == NULL && *tail == NULL)    // empty list case
    {
        new->nxt = NULL;    // no next node
        *head = *tail = new;  // head and tail both point to new
    } 
    else 
    {
        new->nxt = *head;// new points forward to old head
        (*head)->prev = new;// old head points back to new
        *head = new; // update head to new node
    }
}

// Print all digits in the list
void printlist(n *head) 
{
    while (head) 
    {
        printf("%d", head->data);  // print digit
        head = head->nxt;   // move forward
    }
    printf("\n");
}

// Compare two lists by magnitude
int list_compare(n *list1, n *list2) 
{
    int list1_count = 0, list2_count = 0;
    n *temp1 = list1;
    n *temp2 = list2;


    // count digits in list1
    while (temp1) 
    {
        list1_count++;
        temp1 = temp1->nxt;
    }

    // count digits in list2
    while (temp2)
     {
        list2_count++;
        temp2 = temp2->nxt;
    }


    // longer list is greater

    if (list1_count > list2_count)
        return 1;
    else if (list1_count < list2_count)
        return -1;
    else 
    {
         // same length → compare digit by digit
        temp1 = list1;
        temp2 = list2;
        while (temp1 && temp2) 
        {
            if (temp1->data > temp2->data)
                return 1;
            else if (temp1->data < temp2->data)
                return -1;
            temp1 = temp1->nxt;
            temp2 = temp2->nxt;
        }
        return 0; // equal or list1 >= list2
    }
}

// Free all nodes in a list
int deletelist(n **headR, n **tailR)
{
    n *temp = *headR;
    while (temp != NULL) 
    {
        n *next = temp->nxt;  // save next node
        free(temp);   // free current node
        temp = next;  // move forward
    }
    *headR = NULL;
    *tailR = NULL;
    return 0;
}

