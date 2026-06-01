#include <iostream>
//#include <algorithm>
#include <math.h>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    unordered_map<char, int> romanToInteger = {
        {'I',    1},
        {'V',    5},
        {'X',   10},
        {'L',   50},
        {'C',  100},
        {'D',  500},
        {'M', 1000}
    };

    int romanToInt(string s) {
        int res = 0;
        char c, preC;
        for (int i = s.size() - 1; i >= 0; i--) {
            c = s[i];
            if (romanToInteger[c] < romanToInteger[preC]) {
                res -= romanToInteger[c];
            }
            else {
                res += romanToInteger[c];
            }
            preC = c;
        }
        return res;
    }
};