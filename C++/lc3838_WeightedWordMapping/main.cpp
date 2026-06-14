#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans;

        for (auto& word : words) {
            int character = 0;
            for (auto& w : word) {
                character += weights[int(w) - 97];
            }
            character %= 26;
            ans.push_back(char(97 + 25 - character));
        }

        return ans;
    }
};