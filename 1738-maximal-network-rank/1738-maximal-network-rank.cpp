class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<unordered_set<int>> adj(n);
        vector<int>Degree(n,0);
        for(auto x:roads){
            adj[x[0]].insert(x[1]);
            adj[x[1]].insert(x[0]);
            Degree[x[0]]++;
            Degree[x[1]]++;
        }
        int ans=0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int temp = Degree[i]+ Degree[j];
                ans= adj[i].count(j) ? max(ans,temp-1):max(ans,temp);
            }
        }
        return ans;
    }
};