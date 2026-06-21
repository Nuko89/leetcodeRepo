#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end(), std::greater<int>());
        int ans = 0;
        int cost;
        while (coins > 0 && !costs.empty()) {
            cost = *(costs.end() - 1);
            if (cost > coins) break;
            coins -= cost;
            costs.pop_back();
            ans++;
        }
        return ans;
    }
};