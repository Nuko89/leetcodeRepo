#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    double angleClock(int hour, int minutes) {
        double ans;
        ans = abs((hour * 30 + minutes * 0.5) - minutes * 6);
        if (ans > 180) {
            ans = 360 - ans;
        }
        return ans;
    }
};