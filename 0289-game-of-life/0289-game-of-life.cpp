class Solution {
public:
    vector<vector<int>> ways={{0,1},{1,0},{1,1},
        {0,-1},{-1,0},{-1,1},{-1,-1},{1,-1}};
    
    
    void gameOfLife(vector<vector<int>>& board) {
        int n=board.size(),m=board[0].size();
        set<pair<int,int>>zero;
        set<pair<int,int>>one;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int cnt1=0;
                for(auto x:ways){
                    int n_i=i+x[0];
                    int n_j=j+x[1];
                    if(n_i>=0 && n_j>=0 && n_i<n && n_j<m)
                    {
                        if(abs(board[n_i][n_j])==1)cnt1++;
                    }
                }
                if((board[i][j])==1){
                    if(cnt1<2 || cnt1>3)board[i][j]=-1;
                }
                else {
                    if(cnt1==3)board[i][j]=2;
                }
            }
        }
        for(int ro=0;ro<n;ro++){
            for(int col=0;col<m;col++){
                if(board[ro][col]== -1)board[ro][col]=0;
                else if(board[ro][col]==2)board[ro][col]=1;
            }
        }
        
    }
};