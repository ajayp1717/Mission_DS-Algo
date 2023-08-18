class Solution {
public:
    // bool compArr(const vector<int>& a, const vector<int>& b){
    //     return a.size() > b.size();
    // }
    bool hasEdge(int u, int v,vector<vector<int>>& adj) {
        for (int neighbor : adj[u]) {
            if (neighbor == v) {
                return true;
            }
        }
        return false;
    }
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<int>> adj(n);
        for(auto x:roads){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        int ans=0;
        for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int temp = adj[i].size() + adj[j].size();
            if (hasEdge(i, j, adj)) {
                ans = std::max(ans, temp - 1);
            } else {
                ans = std::max(ans, temp);
            }
        }
    }

    //     sort(adj.begin(),adj.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
    //     return a.size() > b.size();
    // });

        // for(auto y:adj){
        //     for( auto x:y){
        //         cout<<x<<" ";
        //     }
        //     cout<<endl;
        // }

        return ans;
        
    }
};