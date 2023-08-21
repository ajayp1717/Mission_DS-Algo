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
    int sum=0;
    void helper(TreeNode* node,int curr){
        if(node){
            curr=curr*10 +node->val;
            
            if(!node->right && !node->left)
                sum+=curr;

            helper(node->left,curr);
            helper(node->right,curr);
        }
    }
    int sumNumbers(TreeNode* root) {
        
        helper(root,0);
        return sum;
    }
};