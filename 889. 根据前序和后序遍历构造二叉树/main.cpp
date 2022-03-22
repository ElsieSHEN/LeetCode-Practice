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
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        return build(preorder, 0, preorder.size()-1, postorder, 0, postorder.size()-1);
    }

    TreeNode* build(vector<int>& preorder, int preStart, int preEnd, vector<int>& postorder, int postStart, int postEnd) {
        if (preStart > preEnd) return nullptr;
        if (preStart == preEnd) return new TreeNode(preorder[preStart]);

        int rootVal = preorder[preStart];
        int leftRootval = preorder[preStart+1];
        int idx = 0;
        for (int i=postStart; i<postEnd; i++) {
            if (postorder[i] == leftRootval) {
                idx = i;
                break;
            }
        }

        int leftSize = idx - postStart + 1;
        TreeNode* root = new TreeNode(rootVal);
        root->left = build(preorder, preStart+1, preStart+leftSize, postorder, postStart, idx);
        root->right = build(preorder, preStart+leftSize+1, preEnd, postorder, idx+1, postEnd);
        return root;
    }
};