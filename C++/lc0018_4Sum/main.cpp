#include <iostream>
#include <algorithm>
//#include <string>
#include <vector>
//#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());
        
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
                if (x == 0) {//find!
                    vector<int> a = {nums[i], nums[j], nums[k]};
                    ans.push_back(a);

                    //去除重複j
                    int lastJ = nums[j];
                    while (j < k && nums[j] == lastJ) j++;

                    //去除重複k
                    int lastK = nums[k];
                    while (j < k && nums[k] == lastK) k--;
                }
                else if (x > 0) {
                    k--;
                }
                else if (x < 0) {
                    j++;
                }
            }
        }

        return ans;
    }
};