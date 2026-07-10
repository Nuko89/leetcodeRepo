#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    long long sumAndMultiply(int n) {
        long long x;
        long long sum = 0, nzero = 0, dgts = 1;
        while (n > 0) {
            x = n % 10;
            if (x > 0) {
                sum     += x;
                nzero   += x * dgts;
                dgts    *= 10;
            }
            n       /= 10;
        }

        return nzero * sum;
    }
};