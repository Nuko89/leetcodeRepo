#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        // 建立鄰接表,並把自己加進自己的鄰接表
        vector<vector<int>> adj(n);
        for(auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        for (int i = 0; i < n; i++) {
            adj[i].push_back(i);//放入自己
            sort(adj[i].begin(), adj[i].end());
        }

        // 用 map<vector<int>, int> 統計每種 pattern 出現的次數
        map<vector<int>, int> patternCount;
        for (int i = 0; i < n; i++) {
            patternCount[adj[i]]++;
        }

        // 驗證:pattern 的長度 == 該 pattern 出現的次數
        int ans = 0;
        for (auto& [pattern, cnt] : patternCount) {
            if ((int)pattern.size() == cnt) {
                ans++;
            }
        }
        return ans;
    }
};