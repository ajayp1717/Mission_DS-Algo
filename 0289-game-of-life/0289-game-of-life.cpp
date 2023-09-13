class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n=board.size(),m=board[0].size();
        vector<vector<int>> ways={{0,1},{1,0},{1,1},
        {0,-1},{-1,0},{-1,1},{-1,-1},{1,-1}};
        
        vector<vector<int>>ans=board;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int cnt1=0;
                for(auto x:ways){
                    int n_i=i+x[0];
                    int n_j=j+x[1];
                    if(n_i>=0 && n_j>=0 && n_i<n && n_j<m)
                    {
                        if(board[n_i][n_j]==1)cnt1++;
                    }
                }
                if(board[i][j]==1){
                    if(cnt1<2 || cnt1>3)ans[i][j]=0;
                }
                else{
                    if(cnt1==3)ans[i][j]=1;
                }
            }
        }
        board=ans;
        
    }
};