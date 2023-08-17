class Solution {
public:
    void helper(int idx, int k, int n, vector<vector<int>>& ans, vector<int>& ds) {
        if (ds.size() == k) {
            if (n == 0 ) {
                ans.push_back(ds);
            }
            return;
        }
        if(n<idx)return;
        for (int i = idx; i <= 9 ; ++i){
            ds.push_back(i);
            helper(i+ 1, k, n-i, ans, ds);
            ds.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> ds;
        
        helper(1, k, n, ans, ds);
        return ans;
    }
};
