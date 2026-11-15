#include <stdio.h>
#include <stdlib.h>
#include "apc.h"
void subnumber(n *head1, n *tail1, n *head2, n *tail2,n **headR, n **tailR) 
{
    int borrow = 0;   //keep track of borrow 
    n *temp1 = tail1; // start from digit of list 1
    n *temp2 = tail2; //start from digit of list 2

    while (temp1 != NULL || temp2 != NULL) 
    {
           int data = -borrow;// start with borrow

        // Case 1: both lists have digits
        if (temp1 != NULL && temp2 != NULL) 
        {
          data += temp1->data - temp2->data; // subtract digit2 from digit1
            temp1 = temp1->prev;               // move to next digit in list1
            temp2 = temp2->prev;               // move to next digit in list2
        }
        // Case 2: only list1 has digits
        else if (temp1 != NULL && temp2 == NULL) 
        {
            data += temp1->data; // digit from the list1
            temp1 = temp1->prev;
        }
        // Case 3: only list2 has digits
        else if (temp1 == NULL && temp2 != NULL) 
        {
            data -= temp2->data;  //subtract digit from list2
            temp2 = temp2->prev;
        }

        // Borrow handling
        if (data < 0)
         {
            data += 10;  
            borrow = 1; //set borrow for the next iteration
        } 
        else
         {
            borrow = 0; //reset the borrow if needed
        }

        insertfirst(headR, tailR, data);  //insert result digit at the front
    }
    //remove the leading zeros from result 
     while (*headR && (*headR)->data == 0 && (*headR)->nxt != NULL)
    {
        n *temp = *headR;
        *headR = (*headR)->nxt;
        (*headR)->prev = NULL;
        free(temp);
    }

}



    