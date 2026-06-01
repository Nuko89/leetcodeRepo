#include <iostream>
//#include <algorithm>
//#include <math.h>
//#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size();
        vector<bool> find(10001, false);
        for (auto num : nums) {
            if (find[num]) return num;
            else find[num] = true;
        }
        return 0;
    }
};