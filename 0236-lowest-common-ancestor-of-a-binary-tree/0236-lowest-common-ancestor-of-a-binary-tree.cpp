/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)return NULL;
        if(root->val==p->val || root->val==q->val)return root;
        
        TreeNode* leftS=lowestCommonAncestor(root->left,p,q);
        TreeNode* rightS=lowestCommonAncestor(root->right,p,q);
        if(leftS && rightS)return root;
        if(!rightS)return leftS;
        else if(!leftS)return rightS;

        return NULL;
        
    }
};