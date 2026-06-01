#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int n = apple.size();
        int m = capacity.size();
        int ans = 0;

        int apples = 0;
        for(int i = 0; i < n; i++) {apples += apple[i];}

        sort(capacity.begin(), capacity.end(), greater<int>());

        for(int i = 0; i < m && apples > 0; i++) {
            apples -= capacity[i];
            ans++;
        }

        return ans;
    }
};