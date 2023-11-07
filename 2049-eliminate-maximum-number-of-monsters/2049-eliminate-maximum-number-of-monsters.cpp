class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        for (int i = 0; i < dist.size(); ++i)
            dist[i] = (dist[i] - 1) / speed[i];
        priority_queue<int, vector<int>, greater<int>> pq(begin(dist), end(dist));
        for (int i = 0; i < dist.size() && i <= pq.top(); ++i)
            pq.pop();
        return dist.size() - pq.size();
    }   
};
