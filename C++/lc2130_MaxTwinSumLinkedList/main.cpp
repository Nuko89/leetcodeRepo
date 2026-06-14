#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long min = LONG_LONG_MAX;
        long long max = 0;

        for (auto& l : nums) {
            if (l < min) min = l;
            if (l > max) max = l;
        }

        return (max - min) * (long long) k;
    }
};