class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int ans = 0;
        int colSize = strs[0].size();
        int rowSize = strs.size();
        bool fnd;
        
        for (int col = 0; col < colSize; col++)
        {
            fnd = true;
            for (int row = 1; row < rowSize; row++)
            {
                //cout << strs[row - 1][col] << "," << strs[row][col] << endl;
                if (strs[row - 1][col] > strs[row][col])
                {
                    ans++;
                    fnd = false;
                    //cout << ans << endl;
                    break;
                }
            }
            
            if (fnd == true) {
                //cout << "good" << endl;
                break;
            }
        }

        return ans;
    }
};