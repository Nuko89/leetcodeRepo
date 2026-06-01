#include <iostream>
//#include <algorithm>
#include <math.h>
//#include <string>
#include <vector>
//#include <queue>
//#include <stack>
//#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> vec;

    bool find(int target) {
        for (auto v : vec) {
            if (v == target) return true;
        }
        return false;
    }

    bool isHappy(int n) {
        int v;
        while (!find(n)) {
            vec.push_back(n);
            v = 0;
            while (n > 0) {
                v += pow(n % 10, 2);
                n /= 10;
            }
            if (v == 1) return true;
            n = v;
        }
        return false;
    }
};

/*別人寫的
class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> visit;
        
        while (visit.find(n) == visit.end()) {
            visit.insert(n);
            n = getNextNumber(n);
            if (n == 1) {
                return true;
            }
        }
        
        return false;
    }

private:
    int getNextNumber(int n) {
        int output = 0;
        
        while (n > 0) {
            int digit = n % 10;
            output += digit * digit;
            n = n / 10;
        }
        
        return output;
    }
};*/