#include <stdio.h>
#include <stdlib.h>

int minSubArrayLen(int target, int* nums, int numsSize) {
    int left = 0, sum = 0;
    int min_len = INT_MAX;

    for (int right = 0; right < numsSize; right++) {
        sum += nums[right];
        while (sum >= target) {
            int len = right - left + 1;
            if (min_len > len) {
                min_len = len;
            }
            sum -= nums[left];
            left++;
        }
    }
    
    return min_len == INT_MAX ? 0 : min_len;
}