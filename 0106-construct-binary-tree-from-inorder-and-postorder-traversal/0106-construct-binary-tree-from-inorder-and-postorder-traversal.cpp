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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        if(postorder.empty())return NULL;
        unordered_map<int,int>Mp;
        for(int i=0;i<inorder.size();i++)Mp[inorder[i]]=i;

        TreeNode* root=new TreeNode(postorder[postorder.size()-1]);
        int rootIdx=Mp[root->val];

        vector<int>leftIO(inorder.begin(),inorder.begin()+rootIdx);
        vector<int>rightIO(inorder.begin()+rootIdx+1,inorder.end());

        vector<int>leftPO(postorder.begin(),postorder.begin()+leftIO.size());
        vector<int>rightPO(postorder.begin()+leftIO.size(),postorder.end()-1);

        root->left=buildTree(leftIO,leftPO);
        root->right=buildTree(rightIO,rightPO);

        return root;
        
    }
};