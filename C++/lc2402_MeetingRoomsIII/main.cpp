#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        //int m = meetings.size();
        int ansRoom = 0;

        sort(meetings.begin(), meetings.end());

        vector<int> usedCount(n, 0);

        // 所有房間一開始都是空的
        priority_queue<int, vector<int>, greater<int>> freeRooms;
        for (int i = 0; i < n; i++) {
            freeRooms.push(i);
        }

        // 使用中的房間
        priority_queue<
            pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>
        > busyRooms;

        for (auto& m : meetings) {//逐一拿出每個 meeting
            /*等價
            for (int i = 0; i < meetings.size(); i++) {
                vector<int>& m = meetings[i];
                // ...
            }
            
            auto	編譯器自動推導型別
            &	reference（參考），不複製資料
            m	指向 meetings[i]
            */
            long long start = m[0]; //meetings[i][0]
            long long end   = m[1]; //meetings[i][0]
            long long duration = end - start;

            // 釋放已經結束的房間
            while (!busyRooms.empty() && busyRooms.top().first <= start) {
                int room = busyRooms.top().second;
                busyRooms.pop();
                freeRooms.push(room);
            }

            // 分配房間
            if (!freeRooms.empty()) {
                // 有空房：直接用
                int room = freeRooms.top();
                freeRooms.pop();
                busyRooms.push({end, room});
                usedCount[room]++;
            } else {
                // 沒空房：等最早結束的
                auto [finishTime, room] = busyRooms.top(); //結構化綁定
                /*等價
                auto p = busyRooms.top();
                long long finishTime = p.first;
                int room = p.second;
                */
                busyRooms.pop();

                long long newEnd = finishTime + duration;
                busyRooms.push({newEnd, room});
                usedCount[room]++;
            }
        }

        /*時序執行會TLE
        vector<int> roomsUsedtimes(n, 0);//計數
        vector<int> roomsUsed(n, -1);//使用中
        vector<pair<int,int>> meetBegin(n), meetEnd(n);//開始與結束時間
        for (int i = 0; i < n; i++) {
            meetBegin[i] = {meetings[i][0], i};
            meetEnd[i]   = {meetings[i][1], i};
        }
        sort(meetBegin.begin(), meetBegin.end());
        sort(meetEnd.begin(),   meetEnd.end());
        
        int i = 0, j = 0, r = 0, rr = 0, ii = 0;
        for (int t = 0; ; t++) {
            //開房
            if (meetBegin[i].first == t && r < n) {
                roomsUsed[r] = meetBegin[i].second;//入住
                roomsUsedtimes[r]++;//房間計數
                for (rr = r; rr < n; rr++) {
                    if (roomsUsed[rr] == -1) {
                        r = rr;//指向下個可用房間
                        break;
                    }
                }
                if (rr == n) r = n;//無房間可住
            }
            //有人要住，但無房可住
            else if (meetBegin[i].first == t && r == n) {
                for (ii = i; ii < m; ii++) {
                    if (meetBegin[ii].first <= t) {
                        meetBegin[ii].first++;
                        break;
                    }
                }
            }
            
            //退房
            if (meetEnd[j].first == t) {
                for (rr = 0; rr < n; rr++) {
                    if (roomsUsed[rr] == meetEnd[j].second) {
                        roomsUsed[rr] = -1;
                        if (rr < r) {//如果退房以現在指針更早
                            r = rr;//指向最前可用房間
                        }
                        break;
                    }
                }
            }
        }
        */

        for (int i = 1; i < n; i++) {
            if (usedCount[i] > usedCount[ansRoom]) {
                ansRoom = i;
            }
        }

        return ansRoom;
    }
};