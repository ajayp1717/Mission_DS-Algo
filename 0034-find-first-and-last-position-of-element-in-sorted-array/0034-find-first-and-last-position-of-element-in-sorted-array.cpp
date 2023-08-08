class Solution {
public:
    int lBound(vector<int> &nums,int n,int k){
        int lo=0,hi=n-1;
        int mid;
        while(lo<=hi){
            mid=(lo+hi)/2;
            if(nums[mid]<k){
                lo=mid+1;
            }
            else hi=mid-1;
        }
        return lo;

    }
    int uBound(vector<int> &nums,int n,int k){
        int lo=0,hi=n-1;
        int mid;
        while(lo<=hi){
            mid=(lo+hi)/2;
            if(nums[mid]>=k){
                hi=mid-1;
            }
            else lo=mid+1;
        }
        return lo;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        
        int n=nums.size();
        int lb=lBound(nums,n,target);
        int ub=lBound(nums,n,target+1)-1; //lb for nxt will be ub for curr
        if(lb==n || nums[lb]!=target)
            return {-1,-1};
        

        return {lb,ub};
    }
};