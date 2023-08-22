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
    
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        vector<int> a1,a2;
        inorder(root1,a1);
        inorder(root2,a2);

        int p1=0,p2=a2.size()-1;
        while(p1<a1.size() && p2>=0){
            int sum=a1[p1]+a2[p2];
            if(sum==target)return true;
            else if(sum>target)p2--;
            else    p1++;
        }
        return false;
    }
};