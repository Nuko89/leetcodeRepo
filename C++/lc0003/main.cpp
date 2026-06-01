#include <iostream>
//#include <algorithm>
#include <string>
#include <queue>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int max_len = 0, l = 0;
        vector<bool> seen(256, false);

        for(int r = 0; r < n; r++)
        {
            // 如果 s[r] 已經出現過，縮小左邊
            while (seen[s[r]]){
                seen[s[l]] = false;
                l++;
            }

            seen[s[r]] = true;
            max_len = max(max_len, r - l + 1);
        }

        return max_len;
    }
};