#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) {
            if (a[0] != b[0]) return a[0] < b[0];
            return a[1] > b[1];
        });

        int cnt = 0, max_end = 0;
        for (auto& iv : intervals) {
            if (iv[1] > max_end) {
                cnt++;
                max_end = iv[1];
            }
        }
        
        return cnt;
    }
};