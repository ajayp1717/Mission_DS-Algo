class Solution {
public:
    vector<vector<int>> ds;
    
    void addSubsets(vector<int>& nums,vector<int> ds0,int i){
        ds.push_back(ds0);
    
       for(;i<nums.size();++i){
           ds0.push_back(nums[i]);
            addSubsets(nums,ds0,i+1);
            ds0.pop_back();
       }
    }

    vector<vector<int>> subsets(vector<int>& nums) {

        vector<int> ds0;
        addSubsets(nums,ds0,0);

        return ds;
    }
};