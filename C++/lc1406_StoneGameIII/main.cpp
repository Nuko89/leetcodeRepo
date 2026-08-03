#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(n + 1, 0);
        vector<int> suffixSum(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            suffixSum[i] = suffixSum[i + 1] + stoneValue[i];
        }

        for (int i = n - 1; i >= 0; i--) {
            dp[i] = INT_MIN;
            for (int k = 1; k <= 3 && i + k <= n; k++) {
                int take = suffixSum[i] - suffixSum[i + k]; //前 i ~ i + k 堆和
                dp[i] = max(dp[i], take - dp[i + k]);
            }
        }

        if (dp[0] > 0) {
            return "Alice";
        }
        else if (dp[0] < 0) {
            return "Bob";
        }
        else {
            return "Tie";
        }
    }
};