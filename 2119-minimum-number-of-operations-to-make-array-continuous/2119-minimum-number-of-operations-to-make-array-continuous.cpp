class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int ans=n;

        set<int>unq(nums.begin(),nums.end());
        vector<int>temp;
        for(auto x:unq)temp.push_back(x);

        for(int i=0;i<temp.size();i++){
            int left=temp[i];
            int right=left+n-1;
            int k=upper_bound(temp.begin(),temp.end(),right)-temp.begin();

            int cnt=k-i;
            ans=min(ans,n-cnt);
        }
        return ans;
    }
};