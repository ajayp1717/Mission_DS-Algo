class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        long long lo=0,hi=1e9,mid;
        long long res=1e9;

        while(lo<=hi){
            mid=lo+(hi-lo)/2;
            int cnt=0;
            for(int i=n-2;i>=0;i--){
                int diff=nums[i+1]-nums[i];
                if(diff<=mid){
                    cnt++;
                    i--;
                }
            }
            if(cnt>=p){
                res=min(res,mid);
                hi=mid-1ll;
            }
            else lo=mid+1ll;
        }
        return res;
    }
};