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

// 递归
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        int left = minDepth(root->left);
        int right = minDepth(root->right);
        if (left == 0 || right == 0) return max(left, right)+1;
        return min(left, right)+1;
    }
};

// BFS
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        queue<pair<TreeNode*, int>> q;
        q.emplace(root, 1);
        while (!q.empty()) {
            TreeNode* cur = q.front().first;
            int depth = q.front().second;
            q.pop();
            if (cur->left == nullptr && cur->right == nullptr) return depth;
            if (cur->left != nullptr) q.emplace(cur->left, depth+1);
            if (cur->right != nullptr) q.emplace(cur->right, depth+1);
        }
        return 0;
    }
};