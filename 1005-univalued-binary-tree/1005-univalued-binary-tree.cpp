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
    int temp=-1;

    bool isUnivalTree(TreeNode* root) {
        if(!root)return true;
        
        if(temp<0)temp=root->val;
        
        return root->val==temp &&
        isUnivalTree(root->left) &&
        isUnivalTree(root->right);

    }
};