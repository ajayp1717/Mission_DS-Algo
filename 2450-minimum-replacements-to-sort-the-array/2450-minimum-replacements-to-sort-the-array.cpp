class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {

        int n=nums.size();
        long long ans=0;
        long long prev=nums[n-1];
        for(int i=n-2;i>=0;i--){
            
            long long parts=ceil(nums[i]/(double)prev);

            ans+=(parts-1);

            prev=nums[i]/parts;    
        }
        return ans;
        
    }
};