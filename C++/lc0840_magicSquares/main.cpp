#include<iostream>
#include<vector>
#include<string>
#include <map>

using namespace std;

class Solution {
public:
    bool checkSurroundingNumbers(vector<vector<int>>& grid, int i, int j) {
        vector<bool> number(10, false);

        //檢查重複與範圍
        int v;
        for (int x = -1; x < 2; x++) {
            for (int y = -1; y < 2; y++) {
                v = grid[i + x][j + y];
                if (number[v] || v < 0 || 9 < v) {
                    return false;
                }
                number[v] = true;
            }
        }

        //橫向相加檢查
        for (int y = -1; y < 2; y++) {
            v = grid[i - 1][j + y] + grid[i][j + y] + grid[i + 1][j + y];
            if (v != 15) return false;
        }
        //直向相加檢查
        for (int x = -1; x < 2; x++) {
            v = grid[i + x][j - 1] + grid[i + x][j] + grid[i + x][j + 1];
            if (v != 15) return false;
        }

        return true;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        if (n < 3 || m < 3) return 0;

        int ans;
        //找出中心的5
        for (int i = 1; i < n - 1; i++) {
            for (int j = 1; j < m - 1; j++) {
                if (grid[i][j] == 5) {
                    if (checkSurroundingNumbers(grid, i, j)) ans++;
                }
            }
        }
        
        return ans;
    }
};