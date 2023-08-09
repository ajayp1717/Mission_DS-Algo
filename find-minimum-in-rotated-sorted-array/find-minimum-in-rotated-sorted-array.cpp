class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        if(n==1 || nums[n-1]>nums[0])return nums[0];
        
        int lo=0,hi=n-1;
        int mid;
        while(lo<=hi){
            mid=lo+(hi-lo)/2;
            if(nums[mid]>nums[n-1])
                lo=mid+1;
            else
                hi=mid-1;
        }
        return nums[lo];
    } 
};