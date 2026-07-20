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

    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int maxVal = *max_element(nums.begin(), nums.end());
        vector<long long> cnt(maxVal + 1, 0);
        for (auto& x : nums) cnt[x]++;

        // multiples[d] = 陣列中是 d 的倍數的元素個數
        vector<long long> multiples(maxVal + 1, 0);
        for (int d = 1; d <= maxVal; d++) {
            for (int m = d; m <= maxVal; m += d) {
                multiples[d] += cnt[m];
            }
        }

        // exact[d] 初始化為 gcd 是 d 的倍數的 pair 數
        vector<long long> exact(maxVal + 1, 0);
        for (int d = 1; d <= maxVal; d++) {
            exact[d] = multiples[d] * (multiples[d] - 1) / 2;
        }

        for (int d = maxVal; d >= 1; d--) {
            
        }

        vector<int> gcdPairs;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                gcdPairs.push_back(gcd(nums[i], nums[j]));
            }
        }
        sort(gcdPairs.begin(), gcdPairs.end());

        vector<int> res;
        for (auto& q : queries) {
            res.push_back(gcdPairs[q]);
        }
        return res;
    }
};