#include <iostream>
//#include <algorithm>
//#include <math.h>
//#include <string>
#include <vector>
#include <queue>

using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        int maxSum = INT_MIN;
        queue<TreeNode*> q;
        q.push(root);

        int level = 1;
        int maxSumLevel = 1;
        while (!q.empty()) {
            int levelSize = q.size();
            int sum = 0;
            for (int i = 0; i < levelSize; i++) {
                TreeNode* node = q.front();
                sum += node->val;
                if (node->left)  q.push(node->left);
                if (node->right) q.push(node->right);
                q.pop();
            }

            if (sum > maxSum) {
                maxSum = sum;
                maxSumLevel = level;
            }

            level++;
        }

        return maxSumLevel;
    }
};