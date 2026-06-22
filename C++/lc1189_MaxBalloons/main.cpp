#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int arr[5] = {0};
        
        for (auto& c : text) {
            switch(c) {
                case 'b'  :
                    arr[0]++;
                    break;
                
                case 'a'  :
                    arr[1]++;
                    break;

                case 'n'  :
                    arr[2]++;
                    break;

                case 'l'  :
                    arr[3]++;
                    break;

                case 'o'  :
                    arr[4]++;
                    break;
            
                default :
                    break;
            }
        }
        
        arr[3] /= 2;
        arr[4] /= 2;

        int ans = INT_MAX;
        for (auto& a : arr) {
            ans = min(ans, a);
        }
        return ans;
    }
};