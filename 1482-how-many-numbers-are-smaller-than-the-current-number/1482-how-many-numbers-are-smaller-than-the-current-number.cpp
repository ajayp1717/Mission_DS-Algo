class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {

        vector<int> ans;
        map<int,int>Mp;
        unordered_map<int,int>Mp1;
        for(auto x:nums)Mp[x]++;
        int prev=0;
        for(auto e:Mp){
            Mp1[e.first]=prev;
            prev+=e.second;
        }
        
        for(int i=0;i<nums.size();i++){
            ans.push_back(Mp1[nums[i]]);
        }
        return ans;  
    }
};