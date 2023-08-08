class Solution {
public:
    bool search(vector<int>& nums, int target) {

        int lo=0,hi=nums.size()-1;
        int mid;
        while(lo<=hi){
            mid=lo+(hi-lo)/2;
            if(nums[mid]==target)return true;
            if(nums[mid]==nums[lo]&& nums[mid]==nums[hi]){ //case that causes problem
                lo++,hi--;
                continue;
            }
            if(nums[mid]>=nums[lo]){
                if(target>=nums[lo] && target<=nums[mid]){
                    hi=mid-1;
                }
                else lo=mid+1;
            }
            else{
                if(target>=nums[mid] && target<=nums[hi]){
                    lo=mid+1;
                }
                else hi=mid-1;
            }
        }
        return false;
        
    }
};