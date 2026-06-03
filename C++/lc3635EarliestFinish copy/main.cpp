#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        vector<int> landEnd, waterEnd;

        for(int i = 0; i < landStartTime.size(); i++) {
            landEnd.push_back(landStartTime[i] + landDuration[i]);
        }
        for(int i = 0; i < waterStartTime.size(); i++) {
            waterEnd.push_back(waterStartTime[i] + waterDuration[i]);
        }

        sort(landEnd.begin(), landEnd.end());
        sort(waterEnd.begin(), waterEnd.end());

        int minTime = INT_MAX;

        //water->land
        for(int i = 0; i < landStartTime.size(); i++) {
            int ls = landStartTime[i];
            int ld = landDuration[i];

            auto it = upper_bound(waterEnd.begin(), waterEnd.end(), ls);

            if (it != waterEnd.begin()) minTime = min(minTime, ls + ld);
            
            if (it != waterEnd.end()) minTime = min(minTime, *it + ld);
        }

        //land->water
        for(int i = 0; i < waterStartTime.size(); i++) {
            int ws = waterStartTime[i];
            int wd = waterDuration[i];

            auto it = upper_bound(landEnd.begin(), landEnd.end(), ws);

            if (it != landEnd.begin()) minTime = min(minTime, ws + wd);
            
            if (it != landEnd.end()) minTime = min(minTime, *it + wd);
        }
        
        return minTime;
    }
};