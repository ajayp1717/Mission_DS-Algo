class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        queue<pair<int,int>>Vert;
        vector<bool>vis(m*n,0);
        vector<vector<int>> ans(m,vector<int>(n,0));
        for(int ro=0;ro<m;ro++){
            for(int col=0;col<n;col++){
                if(mat[ro][col]==0){
                    Vert.push(make_pair(ro,col));
                    vis[ro*n+col]=1;
                }
            }
        }   
        int dirn[4][2]={{-1,0},{1,0},{0,1},{0,-1}};

        while(!Vert.empty()){
            int curr_ro=Vert.front().first;
            int curr_col=Vert.front().second;
            Vert.pop();

            for(int i=0;i<4;i++){
                int new_ro=curr_ro+dirn[i][0];
                int new_col=curr_col+dirn[i][1];

                while(new_ro>=0 && new_ro<m && new_col>=0 && new_col<n && !vis[new_ro*n+new_col]){
                    ans[new_ro][new_col]=ans[curr_ro][curr_col]+1;
                    Vert.push(make_pair(new_ro,new_col));
                    vis[new_ro*n+new_col]=1;
                }
            }              
        }
        return ans;     
    }
};