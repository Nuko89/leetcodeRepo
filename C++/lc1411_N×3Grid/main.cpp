#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    //參考別人解題
    int numOfWays(int n) {
        const int MOD = 1000000007;
        //patten A => ABA; patten B => ABC
        //選A => 3; 選B => 2; => 3 * 2;
        //選A => 3; 選B => 2; 選C => 1; => 3 * 2 * 1;
        long long A = 6, B = 6;

        for (int i = 2; i <= n; i++) {
            long long newA = (2 * A + 2 * B) % MOD;//舊A新A => 2; 舊B新A => 2;
            long long newB = (2 * A + 3 * B) % MOD;//舊A新B => 2; 舊B新B => 3;
            A = newA;
            B = newB;
        }

        return (A + B) % MOD;
    }
};