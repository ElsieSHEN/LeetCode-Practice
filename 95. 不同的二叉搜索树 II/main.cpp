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
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return build(1, n);
    }

    vector<TreeNode*> build(int lo, int hi) {
        if (lo > hi) return {nullptr};
        vector<TreeNode*> res;
        for (int i=lo; i<=hi; i++) {
            vector<TreeNode*> leftTree = build(lo, i-1);
            vector<TreeNode*> rightTree = build(i+1, hi);
            for (auto left: leftTree) {
                for (auto right: rightTree) {
                    TreeNode* node = new TreeNode(i);
                    node->left = left;
                    node->right = right;
                    res.push_back(node);
                }
            }
        }
        return res;
    }
};