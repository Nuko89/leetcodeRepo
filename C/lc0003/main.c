#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//不曉得為什麼 MAX_SIZE == 100 才會對

#define MAX_SIZE 100  // 佇列容量

typedef struct {
    char data[MAX_SIZE];
    int front;  // 指向佇列頭
    int rear;   // 指向佇列尾 (最後一個元素的下一個位置)
    int size;   // 當前元素數量
} CharQueue;

// 初始化
void initQueue(CharQueue* q) {
    q->front = 0;
    q->rear = 0;
    q->size = 0;
}

// 判斷空
bool isEmpty(CharQueue* q) {
    return q->size == 0;
}

// 判斷滿
bool isFull(CharQueue* q) {
    //printf("rear:%d\n", q->rear);
    //printf("size:%d\n", q->size);
    return q->rear == MAX_SIZE - 1;
}

// 重整queue
bool resetqueue(CharQueue* q) {
    char tmp[MAX_SIZE];
    for (int i = q->front, j = 0; i < q->rear; i++, j++){
        tmp[j] = q->data[i];
    }

    printf("%s\n", q->data);

    // 把 tmp 複製回 q->data
    memcpy(q->data, tmp, MAX_SIZE * sizeof(char));

    q->front = 0;
    q->rear = q->size;

    printf("resetqueue->%s\n", q->data);

    return true;
}

// 入隊
bool enqueue(CharQueue* q, char c) {
    if (isFull(q)) resetqueue(q);
    q->data[q->rear] = c;
    q->rear = (q->rear + 1) % MAX_SIZE;
    q->size++;
    return true;
}

// 出隊
bool dequeue(CharQueue* q, char* c) {
    if (isEmpty(q)) return false;
    *c = q->data[q->front];
    q->front = (q->front + 1) % MAX_SIZE;
    q->size--;
    return true;
}

// 查看隊首
bool peek(CharQueue* q, char* c) {
    if (isEmpty(q)) return false;
    *c = q->data[q->front];
    return true;
}

// 查看c
bool findqueue(CharQueue* q, char c) {
    if (isEmpty(q)) return false;
    for (int i = q->front; i < q->rear; i++){
        if (q->data[i] == c){
            //printf("%c,%c\n", q->data[i], c);
            return true;
        }
    }
    return false;
}

int lengthOfLongestSubstring(char* s) {
    int length;
    int maxLength = 0;
    CharQueue queue;
    char a, b, c;
    for (int i = 0, j = 0; s[j] != NULL;){
        a = s[i];
        b = s[j];
        //printf("%c,%c\n", a, b);
        //printf("%s\n", queue.data);
        //printf("%d,%d\n", i, j);
        if (findqueue(&queue, b)){
            dequeue(&queue, &c);
            i++;
        }
        else{
            enqueue(&queue, b);
            j++;
        }
        length = j - i;

        if (length > maxLength){
            maxLength = length;
        }
    }
    return maxLength;
}
