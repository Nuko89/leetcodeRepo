#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        vector <int> mp(26, 0);

        int i;
        for (auto& w : word) {
            i = (int)w - (int)'a';
            mp[i]++;
        }
        sort(mp.begin(), mp.end(), greater<int>());

        int res = 0;
        for (int i = 0, t = 1; i < 26; i++) {
            res += mp[i] * (i / 8 + 1);
        }
        return res;
    }
};