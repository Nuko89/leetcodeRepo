#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int i, j, x;
    int* result = (int*)malloc(2 * sizeof(int)); // 配置一個長度為2的陣列
    for(i = 0; i < numsSize; i++){
        for(j = i + 1; j < numsSize; j++){
            x = nums[i] + nums[j];
            if (x == target){
                result[0] = i;
                result[1] = j;
                *returnSize = 2;   // 回傳陣列長度
                return result;     // 回傳陣列
            }
        }
    }

    return 0;
}

//test
int main()
{
    int array[5] = {4, 5, 6, 7, 8};
    for (int i = 0; i < 5; ++i)
    {
        printf("%d ", array[i]);
    }
    puts(""); //換行
    return 0;
}