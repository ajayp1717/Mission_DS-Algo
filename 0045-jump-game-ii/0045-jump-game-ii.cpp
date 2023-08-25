class Solution {
public:
    int jump(vector<int>& nums) {
        
        int n=nums.size();
        int currMx=0;
        int prevMx=0;
        int ans=0;
        for(int i=0;i<n-1;i++){
            currMx=max(currMx,i+nums[i]);

            if(i>=prevMx){
                prevMx=currMx;
                ans++;
            }
        }
        return ans;
    }
};