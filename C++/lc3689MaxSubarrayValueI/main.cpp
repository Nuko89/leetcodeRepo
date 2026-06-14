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
    int pairSum(ListNode* head) {
        ListNode* it = head;
        vector<int> nums = {};
        while(it->next) {
            it = it->next;
            nums.push_back(it->val);
        }
        nums.push_back(it->val);

        int ans = 0, x;
        int size = nums.size() / 2;
        for (int i = 0, j = nums.size() - 1;
             i < size; i++, j--) {
                x = nums[i] + nums[j];
                if (x > ans) ans = x;
        }

        return ans;
    }
};