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
    string traverse(TreeNode* root, vector<TreeNode*>& res, unordered_map<string, int>& hashMap) {
        if (root == nullptr) return "";
        string left = traverse(root->left, res, hashMap);
        string right = traverse(root->right, res, hashMap);
        string subTree = left + "," + right + "," + to_string(root->val); // 后序遍历

        if (hashMap[subTree] == 1) {
            res.push_back(root);
        }
        hashMap[subTree]++;
        return subTree;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> res;
        unordered_map<string, int> hashMap;
        traverse(root, res, hashMap);
        return res;
    }
};