class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>>Pq;
        for(auto num:nums){
            Pq.push(num);
            if(Pq.size()>k)Pq.pop();
        }
        return Pq.top();    
    }
};