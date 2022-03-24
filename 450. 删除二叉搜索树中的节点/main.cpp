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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) return root;
        if (root->val == key) {
            if (root->left == nullptr && root->right == nullptr) return nullptr; // no children
            if (root->left == nullptr) return root->right; // no left child
            if (root->right == nullptr) return root->left; // no right child
            if (root->left != nullptr && root->right != nullptr) { // have both children
                TreeNode* temp = root->right;           
                while (temp->left)    
                temp = temp->left;
                temp->left = root->left; // temp is the minimum value
                root = root->right;  

            }
        } else if (root->val > key) {
            root->left = deleteNode(root->left, key);
        } else {root->right = deleteNode(root->right, key);}
        return root;
    }
};