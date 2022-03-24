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
    int sum = 0;
    TreeNode* convertBST(TreeNode* root) {
        traverse(root);
        return root;

    }

    void traverse(TreeNode* root) {
        if (root == nullptr) return;

        // 中序遍历可升序打印 -> 此处先右子树再左子树可降序打印
        traverse(root->right);
        sum += root->val;
        root->val = sum; // 将原BST的value换成累加值 -> 原BST变成累加树
        traverse(root->left);
    }
};