#include <iostream>
//#include <algorithm>
#include <string>
#include <vector>
//#include <queue>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        if (s == p) return true;

        int n = s.size();
        int m = p.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        dp[0][0] = true;

        for (int i = 0; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 2];
                }
                else if (s[i - 1] == p[j - 1]) {
                    
                }
            }
            

            
            return false;
        }

        return true;
    }
};


                