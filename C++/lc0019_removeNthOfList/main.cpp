#include <iostream>
//#include <algorithm>
//#include <math.h>
//#include <string>
#include <vector>
#include <queue>

using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int end;
        ListNode* iter = head;
        for (end = 0; iter->next != NULL ; end++) {
            iter = iter->next;
        }

        int trgtIdx = end - n + 1;

        iter = head;
        ListNode* preIter;
        for (int i = 0; i < trgtIdx; i++) {
            preIter = iter;
            iter = iter->next;
        }
        
        if (preIter != NULL) preIter->next = iter->next;
        if (iter == head) head = head->next;

        return head;
    }
};