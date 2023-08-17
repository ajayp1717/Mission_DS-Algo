class Solution {
public:
    void helper(int idx, int k, int n, vector<vector<int>>& ans, vector<int>& ds) {
        if (ds.size() == k) {
            if (n == 0 ) {
                ans.push_back(ds);
            }
            return;
        }
        if (idx <=9) {
            ds.push_back(idx);
            helper(idx + 1, k, n-idx, ans, ds);
            ds.pop_back();
            
            helper(idx + 1,k, n,ans,ds);
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> ds;
        
        helper(1, k, n, ans, ds);
        return ans;
    }
};
