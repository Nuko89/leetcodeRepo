#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<pair<int, int>> rnk;
        for (int i = 0; i < n; i++) {
            rnk.push_back(make_pair(i, arr[i]));
        }

        sort(rnk.begin(), rnk.end(), [](const auto& a, const auto& b) {
            return a.second < b.second;
        });
        
        vector<int> res(n);
        int pre = INT_MIN;
        int i = 0;
        for (auto& r : rnk) {
            if (pre != r.second) i++;
            res[r.first] = i;
            pre = r.second;
        }

        return res;
    }
};