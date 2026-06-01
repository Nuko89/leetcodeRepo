#include <iostream>
#include <algorithm>
//#include <string>
#include <vector>
//#include <queue>
#include <math.h>

using namespace std;

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long totalSum = 0;
        int neg = 0;
        int minAbs = INT_MAX;

        for (auto& row : matrix) {
            for (int v : row) {
                if (v < 0) neg++;
                int av = abs(v);
                totalSum += av;
                minAbs = min(minAbs, av);
            }
        }

        //如果負數的個數為奇數，則必須有一個值保持為負數。
        //為了最小化損失，從總和中減去 2 × （最小絕對值）。
        //2LL 等於 (long long)2
        return (neg % 2 == 0) ? totalSum : totalSum - 2LL * minAbs;
    }
};