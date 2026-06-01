#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool isPalindrome(struct ListNode* head) {
    int n = 100000;

    int stack[n];
    int i, j;
    for (j = 0; head != NULL; j++){
        stack[j] = head->val;
        head = head->next;
    }
    j--;

    while(i < j){
        if (stack[i] != stack[j]) return false;
        i++;
        j--;
    }

    return true;
}