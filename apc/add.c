#include <stdio.h>
#include <stdlib.h>
#include "apc.h"

void addnumber(n *head1, n *tail1, n *head2, n *tail2, n **headR, n **tailR)
{
    int carry = 0;   // keeps track of carry during addition
    n *temp1 = tail1;    // start from least significant digit of list1
    n *temp2 = tail2; // start from least significant digit of list2

   // loop until both lists are exhausted
    while (temp1 != NULL || temp2 != NULL)
    {
        int data = carry;     // initialize with carry from previous step

         // Case 1: both lists have digits
        if (temp1 != NULL && temp2 != NULL)
        {
            data = data+temp1->data + temp2->data;// add both digits + carry
            temp1 = temp1->prev; // move left in list1
            temp2 = temp2->prev;// move left in list2
        }

        // Case 2: only list1 has digits left
        else if (temp1 != NULL)
        {
            data = data+temp1->data;   // add digit from list1 + carry
            temp1 = temp1->prev;
        }

        // Case 3: only list2 has digits left
        else if (temp2 != NULL)
        {
            data= data+ temp2->data;      // add digit from list2 + carry
            temp2 = temp2->prev;
        }

        insertfirst(headR, tailR, data % 10); // store result digit
        carry = data / 10;   // update carry for next step
    }


    // leftover carry after finishing both lists
    if (carry)
        insertfirst(headR, tailR, carry);
}
