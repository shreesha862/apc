#include <stdio.h>
#include <stdlib.h>
#include "apc.h"

// Divide list1 by list2 → quotient listQ, remainder listR
void divnumber(n *head1, n *tail1, n *head2, n *tail2,n **headQ, n **tailQ, n **headRem, n **tailRem)
{
    // division by zero check
    if (head2 == NULL)
     {
        printf("Error: Division by zero\n");
        *headQ = NULL; *tailQ = NULL;
        *headRem = NULL; *tailRem = NULL;
        return;
    }

    *headQ = NULL; *tailQ = NULL; // initialize quotient list
    *headRem = NULL; *tailRem = NULL;  // initialize remainder list

    n *remHead = NULL, *remTail = NULL;   // remainder starts empty

       // Traverse dividend digit by digit (like long division)
    for (n *curr = head1; curr != NULL; curr = curr->nxt)
    {
        insertlast(&remHead, &remTail, curr->data); // bring down next digit

        //  leading zeros in remainder
        while (remHead && remHead->data == 0 && remHead->nxt != NULL)
         {
            n *tmp = remHead;
            remHead = remHead->nxt;
            remHead->prev = NULL;
            free(tmp);
        }

        int count = 0;   // quotient digit for this step


          // Keep subtracting divisor until remainder < divisor
        while (list_compare(remHead, head2) >= 0) 
        {
            n *tmpHead = NULL, *tmpTail = NULL;
            subnumber(remHead, remTail, head2, tail2, &tmpHead, &tmpTail);   // subtract divisor
            deletelist(&remHead, &remTail);  // free old remainder
            remHead = tmpHead;
            remTail = tmpTail; 
            count++;  // increment quotient digit
        }

        insertlast(headQ, tailQ, count); // append quotient digit
    }    

    *headRem = remHead; // final remainder
    *tailRem = remTail;

    //  leading zeros in quotient
    while (*headQ && (*headQ)->data == 0 && (*headQ)->nxt != NULL)
     {
         n *tmp = *headQ;
        *headQ = (*headQ)->nxt;
        (*headQ)->prev = NULL;
        free(tmp);
    }
}
