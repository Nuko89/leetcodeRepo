/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* pre = NULL;
    struct ListNode* ths = head;
    struct ListNode* nxt = NULL;
    
    while(ths != NULL){
        nxt = ths->next;
        ths->next = pre;
        pre = ths;
        ths = nxt;
    }

    return pre;
}