#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();

        vector<vector<int>> dp(n, vector<int>(m, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + int(s1[i - 1]);
                }
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += int(s1[i]);
        }
        for (int i = 0; i < m; i++) {
            ans += int(s2[i]);
        }
        ans = ans - (dp[n - 1][m - 1]) * 2;

        return ans;
    }
};