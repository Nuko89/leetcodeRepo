/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNodes(ListNode* l1, ListNode* l2, int c) {
        int tmp, v;
        if (l1 != NULL && l2 != NULL){
            tmp = l1->val + l2->val + c;
        }
        else if (l1 != NULL && l2 == NULL){
            tmp = l1->val + c;
        }
        else if (l1 == NULL && l2 != NULL){
            tmp = l2->val + c;
        }
        else if (l1 == NULL && l2 == NULL && c != 0){
            tmp = c;
        }
        else if (l1 == NULL && l2 == NULL && c == 0){
            return nullptr;
        }
        v = tmp % 10;
        c = tmp / 10;

        ListNode* node = new ListNode();
        node->val = v;

        if (l1 != NULL && l2 != NULL){
            node->next = addTwoNodes(l1->next, l2->next, c);
        }
        else if (l1 != NULL && l2 == NULL){
            node->next = addTwoNodes(l1->next, NULL, c);
        }
        else if (l1 == NULL && l2 != NULL){
            node->next = addTwoNodes(NULL, l2->next, c);
        }
        else if (l1 == NULL && l2 == NULL){
            node->next = NULL;
        }
        
        return node;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int tmp = l1->val + l2->val;
        int v = tmp % 10;
        int c = tmp / 10;

        ListNode* ans = new ListNode();
        ans->val = v;
        ans->next = addTwoNodes(l1->next, l2->next, c);

        return ans;
    }
};