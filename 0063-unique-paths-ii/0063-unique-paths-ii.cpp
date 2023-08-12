class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& Grid) {
        int m=Grid.size();
        int n=Grid[0].size();

        if(Grid[0][0]==1 || Grid[m-1][n-1]==1)return 0;
        vector<vector<int>> dp(m,vector<int>(n,0));
        
        dp[0][0]=Grid[0][0]==0 ? 1:0;

        for(int i=1;i<n;i++){   //fill 1st row
            dp[0][i]=Grid[0][i]==0 ? dp[0][i-1]:0;
        }

        for(int j=1;j<m;j++){  //fill 1st column
            dp[j][0]=Grid[j][0] ==0 ? dp[j-1][0] :0;
        }

        for(int i=1;i<m;i++){  //fill rest of the grid
            for(int j=1;j<n;j++){
                dp[i][j]=Grid[i][j]==0 ? dp[i-1][j]+dp[i][j-1] :0;
            }
        }
        return dp[m-1][n-1];
        
    }
};