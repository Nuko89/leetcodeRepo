#include <iostream>
//#include <algorithm>
#include <math.h>
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
    vector<long long> vals;

    long long dfs(TreeNode* node) {
        long long sum = node->val;
        if (node->left) sum += dfs(node->left);
        if (node->right) sum += dfs(node->right);
        vals.push_back(sum);
        return sum;
    }

    int maxProduct(TreeNode* root) {
        long long sumRoot = dfs(root);

        long long maxPrdct = INT_MIN;
        long long prdct;
        for (auto v : vals) {
            prdct = (sumRoot - v) * v;
            maxPrdct = prdct > maxPrdct ? prdct : maxPrdct;
        }
        return (int)(maxPrdct % 1000000007LL);
    }
};