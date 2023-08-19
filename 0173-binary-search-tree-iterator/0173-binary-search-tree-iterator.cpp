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
class BSTIterator {
public:
    stack<TreeNode*>nodeSt;
    
    BSTIterator(TreeNode* root) {
        while(root){
            nodeSt.push(root);
            root=root->left;
        }
    }
    
    int next() {
        TreeNode* node =nodeSt.top();
        nodeSt.pop();
        if(node->right){
            TreeNode* curr=node->right;
            while(curr){
                nodeSt.push(curr);
                curr=curr->left;
            }
        }
        return node->val; 
    }
    
    bool hasNext() {
        return !nodeSt.empty();
        
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */