#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    vector<int> root;

    // 找到 i 所屬集合的「根節點」（代表元素），並做路徑壓縮
    int find(int i) {
        if (root[i] == i) {
            return i;
        }
        root[i] = find(root[i]); // 路徑壓縮：把沿路節點都直接指向根節點
        return root[i];
    }

    // 合併兩個集合
    void unite(int a, int b) {
        int rootA = find(a);
        int rootB = find(b);
        root[rootA] = rootB;
    }

    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        root.resize(n);
        iota(root.begin(), root.end(), 0);

        for (int i = 0; i < n - 1; i++) {
            if (abs(nums[i] - nums[i + 1]) <= maxDiff) {
                unite(i, i + 1);
            }
        }

        vector<bool> ans;
        for (auto& q : queries) {
            int a = q[0];
            int b = q[1];
            if (find(root[a]) == find(root[b])) {
                ans.push_back(true);
            }
            else {
                ans.push_back(false);
            }
        } 

        return ans;
    }
};