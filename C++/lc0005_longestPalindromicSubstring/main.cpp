#include <iostream>
//#include <algorithm>
#include <string>
#include <vector>
//#include <queue>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n < 2) return s;

        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for (int i = 0; i < n; i++) dp[i][i] = true;

        int i, j, l;
        int maxLen = 1;
        int start = 0;
        for (int l = 2; l <= n; l++) {
            for (int i = 0; i < n - l; i++) {
                j = i + l - 1;

                if (s[i] == s[j]) {//檢查頭尾相同
                    if (l == 2) {//長度等於2就是回文
                        dp[i][j] = true;
                    }
                    else {//取決於中間是不是回文
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                }
                else {
                    dp[i][j] = false;
                }

                if (dp[i][j] && maxLen < l) {
                    maxLen = l;
                    start = i;
                }
            }
        }

        return s.substr(start, maxLen);  //substr(起始位置, 長度)
    }
};