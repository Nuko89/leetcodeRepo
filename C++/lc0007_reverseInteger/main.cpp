#include <iostream>
//#include <algorithm>
//#include <string>
//#include <vector>
//#include <queue>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        int ans = 0;

        while (x != 0) {
            int digit = x % 10;

            // Check for overflow/underflow before updating ans
            if ((ans > INT_MAX / 10) || (ans < INT_MIN / 10)) {
                return 0; // Return 0 if reversing x would cause overflow/underflow
            }

            ans = ans * 10 + digit;
            x /= 10;
        }

        return ans;
    }
};