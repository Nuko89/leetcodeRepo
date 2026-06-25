#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = i; j < n; j++) {
                if (nums[j] == target) {
                    cnt++;
                }

                int gap = j - i;
                if (cnt > gap / 2 + gap % 2) {
                    ans++;
                }
            }
        }
        return ans;
    }
};