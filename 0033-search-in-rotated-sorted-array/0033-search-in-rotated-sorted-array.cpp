class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int lo=0,hi=nums.size()-1;
        int mid;
        
        while(lo<=hi){
            mid=(hi+lo)/2;
            bool isSorted=(nums[lo]<=nums[mid]); //is left half sorted

            if(nums[mid]==target)return mid;
            else if(isSorted){
                if(nums[mid]>=target && nums[lo]<=target)
                    hi=mid-1;
                else lo=mid+1;
            }
            else{               //right half is sorted
                if(nums[hi]>=target && nums[mid]<=target)
                    lo=mid+1;
                else hi=mid-1;
            }
        }
        return -1;
    }
};