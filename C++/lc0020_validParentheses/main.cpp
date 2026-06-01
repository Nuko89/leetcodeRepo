#include <iostream>
//#include <algorithm>
//#include <math.h>
#include <string>
//#include <vector>
//#include <queue>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
public:
    unordered_map<char, char> parentheses = {
        {')', '('},
        {'}', '{'},
        {']', '['}
    };

    bool isValid(string s) {
        stack<char> stk;

        for (auto c : s) {
            if (!stk.empty() && parentheses[c] == stk.top()) {
                stk.pop();
            }
            else {
                stk.push(c);
            }
        }

        if (stk.empty()) return true;
        return false;
    }
};

/*別人版本
class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        unordered_map<char, char> mapping = {{')', '('}, {']', '['}, {'}', '{'}};

        for (char c : s) {
            if (mapping.find(c) == mapping.end()) {
                stack.push(c);
            } else if (!stack.empty() && mapping[c] == stack.top()) {
                stack.pop();
            } else {
                return false;
            }
        }

        return stack.empty();        
    }
};*/