class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int>Mp;
        for(auto x:nums)Mp[x]++;
        int n=nums.size();
        n/=3;
        vector<int>ans;
        for(auto el:Mp){
            if(el.second>n)ans.push_back(el.first);
        }
        return ans;
    }
};