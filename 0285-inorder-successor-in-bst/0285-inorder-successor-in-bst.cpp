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
    void inorder(TreeNode* node, vector<TreeNode*>& ans) {
        if (!node) return;

        inorder(node->left, ans);
        ans.push_back(node);
        inorder(node->right, ans);
    }

    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        vector<TreeNode*> ans;
        inorder(root, ans);

        for (int i = 0; i < ans.size() - 1; i++) {
            if (ans[i] == p) return ans[i + 1];
        }

        return NULL;
    }

};