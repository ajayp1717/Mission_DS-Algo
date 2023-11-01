class Solution {
public:
    void inorder(TreeNode* node,vector<int>& sorted){
        if(!node)return;

        inorder(node->left,sorted);
        sorted.push_back(node->val);
        inorder(node->right,sorted);
    }
    vector<int> findMode(TreeNode* root) {
        vector<int>temp;
        inorder(root,temp);
        unordered_map<int,int>Mp;
        for(auto x:temp)Mp[x]++;
        int maxi=0; 
        for(auto x:Mp){
            maxi=max(maxi,x.second);
        }
        vector<int>ans;
        
        for(auto x:Mp){
            if(x.second==maxi)ans.push_back(x.first);
        } 
        return ans;
    }
};