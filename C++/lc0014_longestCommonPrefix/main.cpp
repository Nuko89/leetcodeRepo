#include <iostream>
//#include <algorithm>
//#include <math.h>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = strs[0];
        for (auto s : strs) {
            for (int i = 0; i < s.size(); i++) {
                if (res[i] != s[i]) {
                    res = res.substr(0, i);
                }
            }
        }
        return res;
    }
};