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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if (nums.size() == 0) return nullptr;

        auto idx = max_element(nums.begin(), nums.end());
        vector<int> l(nums.begin(), idx);
        vector<int> r(idx+1, nums.end());

        TreeNode* root = new TreeNode(*idx);
        root->left = constructMaximumBinaryTree(l);
        root->right = constructMaximumBinaryTree(r);

        return root;

    }
};