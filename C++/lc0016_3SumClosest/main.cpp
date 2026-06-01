#include <iostream>
#include <algorithm>
//#include <string>
#include <vector>
//#include <queue>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = nums[0] + nums[1] + nums[n - 1];
        
        int i, j, k;
        int x;
        for (i = 0; i < n - 2; i++)
        {
            //去除重複i
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            j = i + 1;
            k = n - 1;
            while (j != k) {
                x = nums[i] + nums[j] + nums[k];
                if (abs(target - x) < abs(target - ans)) {//find!
                    ans = x;
                }
                else if (x > target) {
                    k--;
                }
                else if (x < target) {
                    j++;
                }
                else {
                    return ans;
                }
            }
        }

        return ans;
    }
};