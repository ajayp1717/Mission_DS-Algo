class Solution {
public:
    void helper(int idx,vector<int>& nums,vector<int>& ds,vector<vector<int>>& ans){
        ans.push_back(ds);

        for(int i=idx;i<nums.size();++i){
            if(i>idx && nums[i]==nums[i-1])//duplicate case
                continue;
            ds.push_back(nums[i]);
            helper(i+1,nums,ds,ans);
            ds.pop_back();
        }

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int> temp;
        sort(nums.begin(),nums.end());
        helper(0,nums,temp,ans);

        return ans;
    }
};