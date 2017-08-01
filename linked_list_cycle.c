#include <stdio.h>

typedef struct ListNode {
       int val;
       struct ListNode *next;
   } LINK;

int hasCycle(struct ListNode *head);

int main()
{
    printf("Hello, World!\n");

    return 0;
}

int hasCycle(struct ListNode *head)
{
    if (head == NULL)
        return 0;

    struct ListNode *one_step;
    struct ListNode *two_step;

    one_step = head;
    two_step = head;

    while (two_step->next != NULL && two_step->next->next != NULL)
    {
        one_step = one_step->next;
        two_step = two_step->next->next;

        if (one_step == two_step)
            return 1;
    }

    return 0;
}