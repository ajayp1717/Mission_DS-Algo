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
    void inorder(TreeNode* node,vector<int>& temp){
        if(!node)return;
        
        inorder(node->left,temp);
        temp.push_back(node->val);
        inorder(node->right,temp);
    }
    bool findTarget(TreeNode* root, int k) {

        vector<int> temp;
        inorder(root,temp);
        int lo=0,hi=temp.size()-1;

        while(lo<hi){
            int sum=temp[lo]+temp[hi];
            if(sum==k)return true;
            else if(sum>k)hi--;
            else lo++;
        }
        return false;
        
    }
};