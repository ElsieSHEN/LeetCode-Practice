/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void traversal(TreeNode *root, vector<int> &result) {
        if (root == nullptr) return;
        traversal(root->left, result);
        result.push_back(root->val);
        traversal(root->right, result);
    }
    int minDiffInBST(TreeNode* root) {
        vector<int> result;
        traversal(root, result);
        int res = INT_MAX;
        for (int i=1; i<result.size(); i++) {
            res = min(res, result[i]-result[i-1]);
        }
        return res;
    }
};

/* 关联题目：94. 二叉树的中序遍历 */