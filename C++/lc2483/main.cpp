#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        int minIdx = 0;

        //建立關店懲罰
        int p = 0;
        for (int i = 0; i < n; i++) {
            if (customers[i] == 'Y') {
                p += 1;
            }
        }

        int minp = p;
        for (int i = 1; i < n + 1; i++) {
            if (customers[i - 1] == 'Y') {
                p -= 1;
            }
            else if (customers[i - 1] == 'N') {
                p += 1;
            }
            
            if (p < minp) {
                minIdx = i;
                minp = p;
            }
        }

        return minIdx;
    }
};