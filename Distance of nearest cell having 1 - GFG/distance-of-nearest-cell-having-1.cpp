//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    int n=grid.size(),m=grid[0].size();
	    vector<vector<int>>ans(n,vector<int>(m,0));
	    vector<bool>vis(n*m,0);
	    queue<pair<int,int>>q;
	    
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            if(grid[i][j]==1){
	                q.push(make_pair(i,j));
	                vis[i*m+j]=1;
	            }
	        }
	    }
	    int ways[4][2]={{-1,0},{1,0},{0,1},{0,-1}};
	    
	    while(!q.empty()){
	        
	        int c_ro=q.front().first;
	        int c_col=q.front().second;
	        q.pop();
	        for(int i=0;i<4;i++){
	            int n_ro=c_ro+ways[i][0];
	            int n_col=c_col+ways[i][1];
	            
	            while(n_ro>=0 && n_ro<n && n_col>=0 && n_col<m && !vis[n_ro*m+n_col]){
	                ans[n_ro][n_col]=ans[c_ro][c_col]+1;
	                q.push(make_pair(n_ro,n_col));
	                vis[n_ro*m+n_col]=1;
	            }
	            
	        }
	    }
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends