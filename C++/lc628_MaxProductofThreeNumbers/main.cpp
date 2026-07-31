#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        if (n == 3) return nums[0] * nums[1] * nums[2];

        sort(nums.begin(), nums.end(), greater<int>());

        int res = INT_MIN;
        for (int pos = 3; pos >= 0; pos--) {
            int x = 1;
            for (int i = 0; i < pos; i++) {
                x *= nums[i];
            }
            for (int j = n - 1; j >= n - 3 + pos; j--) {
                x *= nums[j];
            }
            if (x > res) res = x;
        }

        return res;
    }
};