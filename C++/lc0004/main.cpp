#include <iostream>
//#include <algorithm>
#include <string>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> mergeSorted(vector<int>& nums1, vector<int>& nums2) {
        vector<int> tmp;
        int n = nums1.size();
        int m = nums2.size();
        
        int i, j;
        for (i = 0, j = 0; i < n && j < m;){
            if (nums1[i] < nums2[j]){
                tmp.push_back(nums1[i]);
                i++;
            }
            else{
                tmp.push_back(nums2[j]);
                j++;
            }
        }
        for (;i < n; i++) tmp.push_back(nums1[i]);
        for (;j < m; j++) tmp.push_back(nums2[j]);

        return tmp;
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double ans = 0.0;
        int n = nums1.size();
        int m = nums2.size();
        vector<int> tmp = mergeSorted(nums1, nums2);
        
        int idx = (n + m) / 2;
        if ((n + m) % 2 == 1){
            ans = (double)tmp[idx];
        }
        else{
            ans = ((double)(tmp[idx - 1] + tmp[idx])) / 2;
        }

        return ans;
    }
};