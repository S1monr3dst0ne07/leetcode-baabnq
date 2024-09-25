/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */



struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode hook;
    struct ListNode* iter = &hook;


    int carry = 0;

    while (l1 || l2 || carry)
    {
        int digit1 = l1 ? l1->val : 0;
        int digit2 = l2 ? l2->val : 0;

        int sum = digit1 + digit2 + carry;
        int digit = sum % 10;
        carry = sum / 10;
        
        iter->next = malloc(sizeof(struct ListNode));
        iter = iter->next;
        
        iter->val = digit;
        iter->next = NULL;

        if (l1) l1 = l1->next;
        if (l2) l2 = l2->next;
    }


    return hook.next;
}