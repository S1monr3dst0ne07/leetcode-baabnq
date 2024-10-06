#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct Node {
 *     int val;
 *     struct Node *next;
 * };
 */

struct Node
{
    int val;
    struct Node* next;
};


struct Node* addTwoNumbers(struct Node* l1, struct Node* l2)
{
    struct Node hook;
    struct Node* iter = &hook;


    int carry = 0;

    while (l1 || l2 || carry)
    {
        int digit1 = l1 ? l1->val : 0;
        int digit2 = l2 ? l2->val : 0;

        int sum = digit1 + digit2 + carry;
        int digit = sum % 10;
        carry = sum / 10;
        
        iter->next = malloc(sizeof(struct Node));
        iter = iter->next;
        
        iter->val = digit;
        iter->next = NULL;

        if (l1) l1 = l1->next;
        if (l2) l2 = l2->next;
    }


    return hook.next;
}
