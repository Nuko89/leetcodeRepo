#include <iostream>
//#include <algorithm>
#include <math.h>
//#include <string>
#include <vector>
//#include <queue>
//#include <stack>
//#include <unordered_map>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int left = 0, sum = 0;
        int min_len = INT_MAX;
        for (int right = 0; right < n; right++) {
            sum += nums[right];
            while (sum >= target) {
                min_len = min(min_len, right - left + 1);
                sum -= nums[left];
                left++;
            }
        }
        return min_len == INT_MAX ? 0 : min_len;
    }
};