#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
//#include <utility>

using namespace std;

class Solution {
public:
    unordered_map<char, string> digitToLetters = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };

    vector<string> ans;

    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        string s;

        if (digits.empty()) return {};

        DFS(digits, n, 0, s);

        return ans;
    }

    void DFS(string digits, int n, int idx, string s) {
        if (idx != n) {
            int m = digitToLetters[digits[idx]].size();

            for (int i = 0; i < m; i++) {
                s.push_back(digitToLetters[digits[idx]][i]);
                DFS(digits, n, idx + 1, s);
                s.pop_back();
            }
            /*GPT精簡寫法
            string letters = digitToLetters[digits[idx]];
            for (char c : letters) {
                s.push_back(c);
                DFS(digits, n, idx + 1, s);
                s.pop_back();       // 回溯
            }*/
        }
        else {
            ans.push_back(s);
        }
    }
};