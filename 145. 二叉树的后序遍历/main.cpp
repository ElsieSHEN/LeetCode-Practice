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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        post_traversal(root, result);
        return result;
    }

    void post_traversal(TreeNode* root, vector<int>& result) {
        if (root == nullptr) return;
        post_traversal(root->left, result);
        post_traversal(root->right, result);
        result.push_back(root->val);
    }
};