#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    string processStr(string s) {
        string ans = {};
        char c;
        for (int i = 0; i < s.size(); i++) {
            c = s[i];
            if (c >= 'a' && c <= 'z') {
                ans += c;
            }
            else if (c == '#') ans += ans;
            else if (c == '%') {
                string tmp = {};
                for (int j = ans.size() - 1;
                j >= 0; j--) {
                    tmp += ans[j];
                }
                ans = tmp;
            }
            else if (c == '*' && !ans.empty()) {
                ans.pop_back();
            }
            printf("%d\n", i);
            printf("%s\n", ans.c_str());
        }

        return ans;
    }
};