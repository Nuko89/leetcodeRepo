#include <iostream>
#include <algorithm>
#include <vector>
//#include "Vector.h"
#include <utility>

using namespace std;

class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();
        int ans = 0;

        sort(events.begin(), events.end());

        vector<vector<int>> byEnd = events;
        sort(byEnd.begin(), byEnd.end(),
        [](auto& a, auto& b) { 
            return a[1] < b[1]; 
        });

        //prefix max
        vector<pair<int,int>> endMax(n);  // (endTime, maxValueSoFar)
        endMax[0] = {byEnd[0][1], byEnd[0][2]};
        for (int i = 1; i < n; i++){
            endMax[i] = {byEnd[i][1], max(byEnd[i][2], endMax[i - 1].second)};
        }

        //尋找一個活動(events[i])之前的最大值
        for (int i = 0; i < n; i++){
            int start = events[i][0];
            int val = events[i][2];

            // binary search
            int l = 0, r = n - 1, idx = -1;
            while (l <= r) {
                int mid = l + (r - l) / 2;
                if (endMax[mid].first < start) {
                    idx = mid;
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }

            int best = (idx == -1 ? 0 : endMax[idx].second);
            ans = max(ans, best + val);

            /*原本做法
            int best;
            for (int j = 0; j < n; j++) {
                if (endMax[j].first < start) {
                    best = endMax[j].second;
                }
            }
            ans = max(ans, best + val);*/
        }

        return ans;
    }
};