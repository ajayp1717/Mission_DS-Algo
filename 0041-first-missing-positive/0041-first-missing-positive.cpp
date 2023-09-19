class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>Mp;
        for(auto x:nums)Mp[x]++;
        int maxi=INT_MAX;

        for(int i=1;i<=maxi;i++){
            if(Mp.find(i)==Mp.end())return i;
        }
        return -1;   
    }
};