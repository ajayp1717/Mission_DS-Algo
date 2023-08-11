class Solution {
public:

    int t[301][5001];
    int solve(int idx,int sum,vector<int>&coins){
        if(sum==0){
            return 1;
        }
        if(idx==coins.size()){
            return 0;
        }
        if(t[idx][sum]!=-1){
            return t[idx][sum];
        }
        if(sum<coins[idx]){
            return t[idx][sum]=solve(idx+1,sum,coins);
        }
        
        int take=solve(idx,sum-coins[idx],coins);
        int skip=solve(idx+1,sum,coins);
        
        return t[idx][sum] =take+skip; 
    }

    int change(int amount, vector<int>& coins) {
        memset(t,-1,sizeof(t));
        return solve(0,amount,coins);   
    }
};