#include <iostream>
//#include <algorithm>
#include <math.h>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string map = "IVXLCDM";
        string res;
        
        int t, i, j;
        for(j = 6; j >= 0; j -= 2){
            int condition = pow(10, j / 2);
            if (num < 4 * condition) {
                t = num / condition;
                for (i = 0; i < t; i++) {
                    res += map[j];
                }
            }
            else if (num < 5 * condition) {
                res += map[j];
                res += map[j + 1];
            }
            else if (num < 9 * condition) {
                res += map[j + 1];

                int t = (num - 5 * condition) / condition;
                for (i = 0; i < t; i++) {
                    res += map[j];
                }
            }
            else if (num >= 9 * condition) {
                res += map[j];
                res += map[j + 2];
            }
            num %= condition;
        }

        return res;
    }
};