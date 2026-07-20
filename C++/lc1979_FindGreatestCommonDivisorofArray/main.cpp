#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }

    int findGCD(vector<int>& nums) {
        vector<int>::iterator maxIter, minIter;
        maxIter = max_element(nums.begin(), nums.end());
        minIter = min_element(nums.begin(), nums.end());

        return gcd(*maxIter, *minIter);
    }
};