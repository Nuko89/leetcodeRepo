#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int gcd(int a, int b) {
        if (a == 0) return b;
        return gcd(b%a, a);
    }

    long long gcdSum(vector<int>& nums) {
        int n = nums.size();

        vector<int> mxi;
        int maxNow = INT_MIN;
        for (auto& n : nums) {
            maxNow = max(maxNow, n);
            mxi.push_back(maxNow);
        }

        vector<int> prefixGcd;
        for (int i = 0; i < n; i++) {
            prefixGcd.push_back(gcd(nums[i], mxi[i]));
        }

        sort(prefixGcd.begin(), prefixGcd.end());

        long long res = 0;
        for (int i = 0, j = nums.size() - 1; i < j; i++, j--) {
            res += gcd(prefixGcd[i], prefixGcd[j]);
        }
        return res;
    }
};