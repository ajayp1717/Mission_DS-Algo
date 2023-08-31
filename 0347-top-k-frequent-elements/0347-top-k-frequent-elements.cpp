class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int>Mp;
        vector<int> ans;
        for(auto x:nums)Mp[x]++;

        auto comp = [](auto& a, auto& b) {
            return a.second < b.second; 
            };

        // Create the priority queue with the custom comparator
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> pq(comp);
            
        for(auto x:Mp){
            pq.push({x.first,x.second});
        }
        while(k--){
            int temp=pq.top().first;
            pq.pop();
            ans.push_back(temp);
        }
        return ans;
    }
};