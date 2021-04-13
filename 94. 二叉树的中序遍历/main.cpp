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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        mid_traversal(root, result);
        return result;
    }

    void mid_traversal(TreeNode* root, vector<int>& result) {
        if (root == nullptr) return;
        mid_traversal(root->left, result);
        result.push_back(root->val);
        mid_traversal(root->right, result);
    }
};

/* 递归 */