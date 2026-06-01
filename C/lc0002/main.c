#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

int* reverseOrder(struct ListNode* lstFrst){
    if (lstFrst->next != NULL){
        printf("%d", lstFrst->val);
        return 0;//10 * *(reverseOrder(lstFrst->next)) + lstFrst->val;
    }
    else {
        return 0;//*(lstFrst->val);
    }
    
}

struct ListNode* addTwoNodes(struct ListNode* l1, struct ListNode* l2, int cVal) {
    int tmp;
    if (l1 != NULL && l2 != NULL){
        tmp = l1->val + l2->val + cVal;
    }
    else if (l1 != NULL && l2 == NULL){
        tmp = l1->val + cVal;
    }
    else if (l1 == NULL && l2 != NULL){
        tmp = l2->val + cVal;
    }
    else if (l1 == NULL && l2 == NULL && cVal != 0){
        tmp = cVal;
    }
    else if (l1 == NULL && l2 == NULL && cVal == 0){
        return NULL;
    }
    
    struct ListNode* tmpNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    tmpNode->val = tmp % 10;
    int carryVal = tmp / 10;
    
    if (l1 != NULL && l2 != NULL){
        tmpNode->next = addTwoNodes(l1->next, l2->next, carryVal);
    }
    else if (l1 != NULL && l2 == NULL){
        tmpNode->next = addTwoNodes(l1->next, NULL, carryVal);
    }
    else if (l1 == NULL && l2 != NULL){
        tmpNode->next = addTwoNodes(NULL, l2->next, carryVal);
    }
    else if (l1 == NULL && l2 == NULL){
        tmpNode->next = NULL;
    }
    return tmpNode;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int tmp = l1->val + l2->val;
    struct ListNode* tmpNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    tmpNode->val = tmp % 10;
    int carryVal = tmp / 10;
    tmpNode->next = addTwoNodes(l1->next, l2->next, carryVal);
    return tmpNode;
}

//test
int main()
{
    int num = 100;
    int *ptr;
    ptr = &num;

    printf("%d\n", *ptr);

    struct ListNode *node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = 12;     // 設定 val
    node->next = NULL;  // 沒有下一個節點
    
    // 使用 val
    printf("節點的值: %d\n", node->val);

    free(node);  // 記得釋放
    
    puts(""); //換行
    return 0;
}