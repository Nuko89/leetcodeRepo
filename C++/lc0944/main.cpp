#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int strSize = strs[0].size();
        int strsSize = strs.size();
        int cnt = 0;

        for (int j = 0; j < strSize; j++){
            for (int i = 1; i < strsSize; i++){
                if (strs[i][j] < strs[i - 1][j]){
                    cnt++;
                    break;
                }
            }
        }
        return cnt;
    }
};