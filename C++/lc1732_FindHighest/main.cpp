#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans = 0;
        int h = 0;
        for (auto & g : gain) {
            h += g;
            ans = max(ans, h);
        }
        return ans;
    }
};