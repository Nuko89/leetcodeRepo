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

    int minScore(int n, vector<vector<int>>& roads) {
        // 初始化：一開始每個城市都自己是一個獨立集合
        root.resize(n + 1);
        iota(root.begin(), root.end(), 0);

        // 把所有有道路相連的城市合併成同一個集合
        for (auto& road : roads) {
            unite(road[0], road[1]);
        }

        // 找出跟城市 1 屬於同一個集合的所有道路，取最小權重
        int res = INT_MAX;
        int group1 = find(1); // 城市 1 所屬的集合代表

        for (auto& road : roads) {
            if (find(road[0]) == group1) {
                res = min(res, road[2]);
            }
        }

        return res;
    }
};