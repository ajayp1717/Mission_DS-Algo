class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum<x)return -1;
        if(sum==x)return n;
        int maxSubarrSum=sum-x;

        int l=0,r,temp=0;
        int maxL=0;
        for(int r=0;r<n;r++){
            temp+=nums[r];

            while(temp>maxSubarrSum){
                temp-=nums[l];
                l++;
            }
            if(temp==maxSubarrSum)maxL=max(maxL,r-l+1);
        }
        return maxL >0 ? n-maxL:-1;
        
    }
};