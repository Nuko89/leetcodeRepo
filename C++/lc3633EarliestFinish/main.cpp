#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int end_l, end_w;
        int minTime = INT_MAX;
        for (int j = 0; j < waterStartTime.size(); j++) {
            end_w = waterStartTime[j] + waterDuration[j];

            for (int i = 0; i < landStartTime.size(); i++) {
                end_l = landStartTime[i] + landDuration[i];
                
                //water->land
                if (landStartTime[i] <= end_w) {
                    minTime = min(minTime, end_w + landDuration[i]);
                }
                else {
                    minTime = min(minTime, end_l);
                }

                //land->water
                if (waterStartTime[j] <= end_l) {
                    minTime = min(minTime, end_l + waterDuration[j]);
                }
                else {
                    minTime = min(minTime, end_w);
                }
            }
        }
        return minTime;
    }
};