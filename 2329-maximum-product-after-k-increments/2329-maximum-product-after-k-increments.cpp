class Solution {
public:
    long long MOD=1e9+7;
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>>pq;
        for(auto x:nums){
            pq.push(x);
        }

        while(k--){
            int temp=pq.top();
            pq.pop();
            pq.push(++temp);
        }
        long long prod=1;
        while(pq.size()>0){
            int num=pq.top();
            pq.pop();
            prod=(prod*num)%MOD;
        }
        return prod;
        
    }
};