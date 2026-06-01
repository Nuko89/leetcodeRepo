#include <iostream>
//#include <algorithm>
#include <string>
//#include <vector>
//#include <queue>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        int i = 0;
        for (; i < n; i++) {
            if (s[i] != ' ') break;
        }
        
        long long Signed = 1;
        if (s[i] == '+') i++;
        else if (s[i] == '-') {
            Signed = -1;
            i++;
        }

        long long ans = 0;
        int digit;
        for (; i < n; i++) {
            if ('0' <= s[i] && s[i] <= '9') {
                digit = s[i] - '0';

                if (Signed * ans > (INT_MAX - digit) / 10) {
                    ans = INT_MAX;
                    break;
                }
                else if (Signed * ans < (INT_MIN + digit) / 10) {
                    ans = INT_MIN;
                    break;
                }
                
                ans = ans * 10 + digit;
            }
            else {
                break;
            }
        }

        return static_cast<int>(ans * Signed);
    }
};