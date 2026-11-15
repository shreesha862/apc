/**
 APC Calculator
 Arbitrary Precision Calculator (APC) 
Purpose:Perform addition, subtraction, multiplication, and division on arbitrarily large integers using doubly linked lists.
 Linked Lists is used Standard integer types (int, long, etc.) have fixed limits.By storing each digit in a node of a doubly linked list,we can represent numbers of any size.
 Operations are performed digit by digit, similar to manual arithmetic.
Program Flow:
 1. Parse command-line arguments:
 argv[1] → first number (may include + or - sign)
 argv[2] → operator (+, -, x, *, /)
 argv[3] → second number (may include + or - sign)
2. Handle signs:
 Detect '+' or '-' at the start of each number.
 Store sign separately (sign1, sign2).
 Strip sign character before building digit lists.
 3. Build linked lists:
 Each digit of the input string is inserted into a doubly linked list.
 Example: "1234" → 1 → 2 → 3 → 4
 4. Perform operation:
Addition: addnumber() or subnumber() depending on signs.
Subtraction: flip sign of second number, then reuse logic.
Multiplication: mulnumber() with sign1 * sign2.
Division: divnumber() with quotient and remainder lists.
 Division by zero is explicitly checked and reported.
 5. Print result:
Correct sign is printed before the result list.
Quotient and remainder are printed for division.
Error Handling:
Invalid characters in input → program prints error and exits.
Division by zero → program prints error and exits.
Unsupported operator → program prints error and exits.
Example Usage:
 ./APC.out 1234 + 567
 Addition Result: 1801
 ./APC.out -1234 x +567
 Multiplication Result: -699678
 ./APC.out 1234 / 567
 Division Result: 2
  Remainder: 100
 */
#include <stdio.h>
#include <string.h>
#include "apc.h"

int main(int argc, char *argv[]) 
{
   if (argc < 4) 
    {
        printf("Not enough arguments\n");   // check if enough arguments are passed
        return 0;
    }

    n *head1 = NULL, *tail1 = NULL;  // linked list for first number
    n *head2 = NULL, *tail2 = NULL;   // linked list for second number
    n *headR = NULL, *tailR = NULL;  // linked list for result

    int sign1 = 1, sign2 = 1;   // track signs of numbers

    // handle signs (+ and -)
    if (argv[1][0] == '-') 
    {
         sign1 = -1;   // mark negative and skip sign char
         argv[1]++;
    }   
    else if (argv[1][0] == '+') 
    { 
        argv[1]++;  // skip plus sign
    }
    if (argv[3][0] == '-')
     { 
        sign2 = -1;    // mark negative and skip sign char
        argv[3]++; 
    }
    else if (argv[3][0] == '+') 
    { 
        argv[3]++;    // skip plus sign
    }

    // build list1 (digits only)
    char *str = argv[1];
    for (int i = 0; str[i] != '\0'; i++) //loop through every char
     {
        if (str[i] >= '0' && str[i] <= '9') //checking isdigit
        {
            insertlast(&head1, &tail1, str[i] - '0');  // insert digit into list1
        } 
        else 
        {
            printf("Invalid character in input: %c\n", str[i]);   // reject non-digit
            return 0;
        }
    }

    //  build list2(digits only)
    str = argv[3];
    for (int i = 0; str[i] != '\0'; i++)  //loop through every char 
     {
        if (str[i] >= '0' && str[i] <= '9') //checking isdigit
        {
            insertlast(&head2, &tail2, str[i] - '0');  // insert digit into list1
        } 
        else
        {
            printf("Invalid character in input: %c\n", str[i]);  // reject non-digit
            return 0;
        }
    }

    int resultSign = 1;  // track sign of result

    // Addition
    if (strcmp(argv[2], "+") == 0) 
    {
        if (sign1 == sign2) 
        {
            addnumber(head1, tail1, head2, tail2, &headR, &tailR);   // same sign → add
            resultSign = sign1;
        } 
        else 
        {
            int cmp = list_compare(head1, head2);  // compare magnitudes
            if (cmp >= 0)
            {
                subnumber(head1, tail1, head2, tail2, &headR, &tailR);    // subtract smaller from larger
                resultSign = sign1;  // result sign = sign of larger
            }
             else 
             {
                subnumber(head2, tail2, head1, tail1, &headR, &tailR);   // subtract smaller from larger
                resultSign = sign2;  // result sign = sign of larger
            }
        }
        printf("Addition Result: ");
        if (resultSign == -1) // print negative sign if needed
        printf("-");
        printlist(headR);    // print result digits
    } 

    // Subtraction
    else if (strcmp(argv[2], "-") == 0) 
    {
        sign2 = -sign2;// flip sign of second number
        if (sign1 == sign2) 
        {
            addnumber(head1, tail1, head2, tail2, &headR, &tailR);  // same sign → add
            resultSign = sign1;
        } 
        else 
        {
            int cmp = list_compare(head1, head2);  // compare magnitudes
            if (cmp >= 0) 
            {
                subnumber(head1, tail1, head2, tail2, &headR, &tailR);  // subtract smaller
                resultSign = sign1;
            } 
            else 
            {
                subnumber(head2, tail2, head1, tail1, &headR, &tailR); // subtract smaller
                resultSign = sign2;
            }
        }
        printf("Subtraction Result: ");
        if (resultSign == -1) 
        printf("-"); // print negative sign if needed
        printlist(headR); // print result digits
    }

    // Multiplication
    else if (strcmp(argv[2], "x") == 0) 
    {
        mulnumber(head1, tail1, head2, tail2, &headR, &tailR);    // multiply lists
        resultSign = sign1 * sign2;    // result sign = product of signs
        printf("Multiplication Result: ");
        if (resultSign == -1) 
        printf("-");   // print negative sign if needed
        printlist(headR); // print result digits
    }

    // Division
    else if (strcmp(argv[2], "/") == 0)
     {

            // check divisor is zero (single node with 0)
        if (head2 == NULL|| (head2->data == 0 && head2->nxt == NULL))
        {
            printf("Error: Division by zero\n");
            return 0;
        }
        n *headQ = NULL, *tailQ = NULL;  // quotient list
        n *headRem = NULL, *tailRem = NULL;  // remainder list
        divnumber(head1, tail1, head2, tail2, &headQ, &tailQ, &headRem, &tailRem);

        resultSign = sign1 * sign2;
        printf("Division Result: ");
        if (resultSign == -1)
         printf("-");   // print negative sign if needed
        printlist(headQ); // print quotient
    }
   else 
    {
        printf("Unsupported operation: %s\n", argv[2]);// error message for invalid operator
    }

    return 0;
}

