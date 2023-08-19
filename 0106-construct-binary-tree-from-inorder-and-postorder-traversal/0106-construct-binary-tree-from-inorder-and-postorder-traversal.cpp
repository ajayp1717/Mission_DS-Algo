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
    unordered_map<int, int> Mp;

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.empty()) return NULL;

        for (int i = 0; i < inorder.size(); i++) {
            Mp[inorder[i]] = i;
        }

        int postIdx = postorder.size() - 1;
        return getTree(postorder, 0, inorder.size() - 1, postIdx);
    }

    TreeNode* getTree(vector<int>& postorder, int left, int right, int& postIdx) {
        if (left > right || postIdx < 0) return NULL;

        int rootVal = postorder[postIdx--];
        TreeNode* root = new TreeNode(rootVal);

        root->right = getTree(postorder, Mp[rootVal] + 1, right, postIdx);
        root->left = getTree(postorder, left, Mp[rootVal] - 1, postIdx);
            
        return root;
    }

};