#include <iostream>
#include <algorithm>
//#include <string>
#include <vector>
//#include <queue>
#include <math.h>

using namespace std;

class Solution {
public:
    bool isPrime(int x) {
        if (x < 2) return false;
        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0) return false;
        }
        return true;
    }

    int sumOne(int n) {
        int p = round(cbrt(n));//找立方根後4捨5入
        if ((long long)p * p * p == n && isPrime(p)) {
            return 1 + p + p*p + p*p*p;
        }

        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                int a = i, b = n / i;
                if (a != b && isPrime(a) && isPrime(b)) {
                    return 1 + a + b + n;
                }
                return -1;
            }
        }
        return -1;
    }

    int sumFourDivisors(vector<int>& nums) {//別人的code
        int res = 0;
        for (int n : nums) {
            int val = sumOne(n);
            if (val != -1) res += val;
        }
        return res;
    }
};