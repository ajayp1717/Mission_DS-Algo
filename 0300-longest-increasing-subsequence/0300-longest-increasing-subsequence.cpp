class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        set<int>temp;

        for(int i=0;i<n;i++){
            auto idx=temp.lower_bound(nums[i]);
            if(idx!=temp.end()){
                temp.erase(idx);
            }
            temp.insert(nums[i]);
        }
        return temp.size();
    }
};