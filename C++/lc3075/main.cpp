#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long ans = 0;

        sort(happiness.begin(), happiness.end(), greater<int>());

        for (int i = 0; i < k && happiness[i] - i > 0; i++)
        {
            ans += happiness[i] - i;
        }

        return ans;
    }
};