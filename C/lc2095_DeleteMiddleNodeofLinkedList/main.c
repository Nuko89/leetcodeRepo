#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteMiddle(struct ListNode* head) {
    if (!(head->next)) return NULL;

    struct ListNode *fst = head;
    struct ListNode *slw = head;
    struct ListNode *prv = NULL;

    while (fst && fst->next) {
        prv = slw;
        slw = slw->next;
        fst = fst->next->next;
    }

    prv->next = slw->next;

    return head;
}