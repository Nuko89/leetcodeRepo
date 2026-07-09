#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*
class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        #define MOD_NUM 1000000007

        vector<int> ans;
        for (auto& q : queries) {
            long long sum = 0, nzero = 0;
            for (int i = q[0]; i <= q[1]; i++) {
                if (s[i] > '0' && s[i] <= '9') {
                    long long x = (long long)s[i] - '0';
                    sum     += x;
                    nzero   *= 10;
                    nzero   += x;
                }
            }

            long long ll = (nzero * sum) % MOD_NUM;
            ans.push_back(ll);
        }
        
        return ans;
    }
};*/

const int MOD       = 1e9 + 7;
const int MAX_NUM   = 1e5 + 1;
long long pow10[MAX_NUM];

// init runs only once for all test cases
int init = []() {
    pow10[0] = 1;
    for (int i = 1; i < MAX_NUM; i++) {
        pow10[i] = (pow10[i - 1] * 10) % MOD;
    }
    return 0;
}();

class Solution {
public:   
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<int> sum(n + 1, 0);
        vector<long long> nzero(n + 1, 0);
        vector<int> cnt(n + 1, 0);
        for (int i = 0; i < n; i++) {
            int d = s[i] - '0';
            sum[i + 1]      = sum[i] + d;
            nzero[i + 1]    = (d > 0) ? (nzero[i] * 10 + d) % MOD : nzero[i];
            cnt[i + 1]      = cnt[i] + (d > 0); // 遇到非零數字,計數 +1
        }

        int m = queries.size();
        vector<int> res(m, 0);
        for (int i = 0; i < m; i++) {
            int l = queries[i][0];
            int r = queries[i][1] + 1;
            int length = cnt[r] - cnt[l];
            long long val_nzero = (nzero[r] - nzero[l] * pow10[length] % MOD + MOD) % MOD;
            long long val_sum = sum[r] - sum[l];
            res[i] = (val_nzero * val_sum) % MOD; 
        }
        return res;
    }
};
