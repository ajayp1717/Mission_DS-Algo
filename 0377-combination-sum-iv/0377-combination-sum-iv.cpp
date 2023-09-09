class Solution {
public:
    
    int combinationSum4(vector<int>& nums, int target) { 
        vector<uint>dp(target+1,0);
        dp[0]=1;
        
        for(int currTar=1;currTar<=target;currTar++){
            for(auto& num:nums)
                if(currTar>=num)
                    dp[currTar]+=dp[currTar-num];
        }
        return dp[target];  
    }
};