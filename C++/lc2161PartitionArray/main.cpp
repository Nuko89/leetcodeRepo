#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> less, greater;
        int pivot_cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < pivot) less.push_back(nums[i]);
            else if (nums[i] > pivot) greater.push_back(nums[i]);
            else pivot_cnt++;
        }

        int it;
        for (int i = 0; i < less.size(); i++) nums[i] = less[i];
        it = less.size();
        for (int i = it; i < it + pivot_cnt; i++) nums[i] = pivot;
        it += pivot_cnt;
        for (int i = it; i < nums.size(); i++) nums[i] = greater[i - it];

        return nums;
    }
};