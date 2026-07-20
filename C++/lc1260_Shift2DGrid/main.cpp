#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        int total = m * n;
        k %= total;
        if (k == 0) return grid;  // 沒有位移，直接回傳原 grid

        int start_i = m - 1 - (k - 1) / n;
        int start_j = n - 1 - (k - 1) % n;
        //cout << start_i << ',' << start_j;
        
        vector<vector<int>> res(m);

        //第一排
        int col = 0;
        for (int j = start_j; j < n; j++, col++) {
            res[col / n].push_back(grid[start_i][j]);
        }

        //後幾排
        for (int i = start_i + 1; i < m; i++) {
            for (int j = 0; j < n; j++, col++) {
                res[col / n].push_back(grid[i][j]);
            }
        }

        //剩餘
        for (int i = 0; i < start_i; i++) {
            for (int j = 0; j < n; j++, col++) {
                res[col / n].push_back(grid[i][j]);
            }
        }
        //最後一排
        for (int j = 0; j < start_j; j++, col++) {
            res[col / n].push_back(grid[start_i][j]);
        }

        return res;
    }
};