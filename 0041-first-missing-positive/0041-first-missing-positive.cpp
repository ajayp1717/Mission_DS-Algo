class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int>st;
        for(auto x:nums)st.insert(x);
        int maxi=INT_MAX;

        for(int i=1;i<=maxi;i++){
            if(!st.count(i))return i;
        }
        return -1;   
    }
};