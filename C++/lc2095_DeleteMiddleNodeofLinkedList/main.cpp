#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

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
    ListNode* deleteMiddle(ListNode* head) {
        if (!(head->next)) return nullptr;

        ListNode *tail = head;
        ListNode *mid = head;
        ListNode *prvmid = nullptr;

        while(tail->next && tail->next->next) {
            prvmid = mid;
            mid = mid->next;
            tail = tail->next->next;
        }
        if (tail->next) {
            prvmid = mid;
            mid = mid->next;
        }

        prvmid->next = mid->next;

        return head;
    }
};