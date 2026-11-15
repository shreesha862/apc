#include <stdio.h>
#include <stdlib.h>
#include "apc.h"

void mulnumber(n *head1, n *tail1, n *head2, n *tail2,n **headR, n **tailR)
{
    int shift = 0; // number of zeros to append for positional value
    n *temp2 = tail2;// start from least significant digit of list2

    // initialize result list
    *headR = NULL;
    *tailR = NULL;

    // traverse list2 from tail (least significant digit)
    while (temp2 != NULL)
    {
        int carry = 0;  // carry for multiplication
        n *temp1 = tail1;  // start from least significant digit of list1
        n *headP = NULL, *tailP = NULL; // partial product list

        // multiply list1 by one digit of list2
        while (temp1 != NULL)
        {
            int prod = temp1->data * temp2->data + carry;
            carry = prod / 10;   // update carry
            insertfirst(&headP, &tailP, prod % 10);  // store digit
            temp1 = temp1->prev;      // move left in list1
        }

        // leftover carry
        if (carry > 0)
            insertfirst(&headP, &tailP, carry);

        // add shift (zeros at the end)
        for (int i = 0; i < shift; i++)
            insertlast(&headP, &tailP, 0);

        // add partial product to result
        if (*headR == NULL)
        {
            *headR = headP;
            *tailR = tailP;
        }
        else
        {
            n *tempHead = NULL, *tempTail = NULL;
            addnumber(*headR, *tailR, headP, tailP, &tempHead, &tempTail);   // add partial product
            deletelist(headR, tailR); // clear old result
            *headR = tempHead;   // update result
            *tailR = tempTail;
        }

        temp2 = temp2->prev;  // move left in list2
        shift++;        // increase shift for next partial product
    }

    // remove leading zeros from final result
    while (*headR && (*headR)->data == 0 && (*headR)->nxt != NULL)
    {
        n *temp = *headR;
        *headR = (*headR)->nxt;
        (*headR)->prev = NULL;
        free(temp);
    }
}