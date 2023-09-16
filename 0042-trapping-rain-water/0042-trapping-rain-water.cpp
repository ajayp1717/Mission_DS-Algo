class Solution {
public:
    int trap(vector<int>& height) {
        
        int ans = 0;
        int n = height.size();
        int l=0,r=n-1;
        int lmax=0,rmax=0;
        while(l<r){
            if(height[r]>height[l]){
               if(height[l] >= lmax){
                   lmax=height[l];
               }
               else{
                   ans+=(lmax-height[l]);
               }
               l++;

            }
            else{
                if(height[r]>=rmax){
                    rmax=height[r];
                }
                else{
                    ans+=(rmax-height[r]);
                }
                r--;
            }
        }
        
        return ans;
    }
};