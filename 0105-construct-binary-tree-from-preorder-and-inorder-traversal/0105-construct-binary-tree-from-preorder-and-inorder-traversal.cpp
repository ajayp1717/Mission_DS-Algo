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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        if(preorder.empty())return NULL;
        
        unordered_map<int,int>Mp;
        for(int i=0;i<inorder.size();i++)Mp[inorder[i]]=i;

        int rootVal=preorder[0];
        TreeNode* root=new TreeNode(rootVal);
        
        int rootIdx=Mp[rootVal];

        vector<int>leftInorder(inorder.begin(),inorder.begin()+rootIdx);
        vector<int>rightInorder(inorder.begin()+rootIdx+1,inorder.end());

        vector<int>leftPreorder(preorder.begin()+1,preorder.begin()+leftInorder.size()+1);
        vector<int>rightPreorder(preorder.begin()+leftInorder.size()+1,preorder.end());

        root->left=buildTree(leftPreorder,leftInorder);
        root->right=buildTree(rightPreorder,rightInorder);

        return root;
        
    }
};