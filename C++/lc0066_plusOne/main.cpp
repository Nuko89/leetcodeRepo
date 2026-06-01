#include <iostream>
#include <algorithm>
#include <string>
//#include <unordered_map>
#include <vector>
//#include <utility>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();

        int c = 1, v;
        for (int i = n - 1; i >= 0; i--) {
            v = digits[i] + c;
            c = v / 10;
            v = v % 10;
            digits[i] = v;
        }
        if (c > 0) {
            digits.insert(digits.begin(), 1);
            /*
            vector <int> tmp(n + 1);
            tmp[0] = c;
            for (int i = 1; i < n + 1; i++) {
                tmp[i] = digits[i - 1];
            }
            return tmp;*/
        }

        return digits;
    }
};