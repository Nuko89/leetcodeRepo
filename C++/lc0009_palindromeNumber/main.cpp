#include <iostream>
//#include <algorithm>
#include <string>
//#include <vector>
//#include <queue>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        
        int tmp = x;
        int y = 0;
        int digit;
        while (tmp > 0) {
            digit = tmp % 10;
            tmp /= 10;

            if (y > (INT_MAX - digit) / 10) return false;

            y = y * 10 + digit;
        }

        return x == y;
    }
};