class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& Grid) {
        int m=Grid.size();
        int n=Grid[0].size();

        if(Grid[0][0]==1 || Grid[m-1][n-1]==1)return 0;
        
        
        Grid[0][0]=1;

        for(int i=1;i<n;i++){   //fill 1st row
            Grid[0][i]=(Grid[0][i]==0 && Grid[0][i-1]==1) ? 1:0;
        }

        for(int j=1;j<m;j++){  //fill 1st column
            Grid[j][0]=(Grid[j][0] ==0 && Grid[j-1][0]==1)? 1:0;
        }

        for(int i=1;i<m;i++){  //fill rest of the grid
            for(int j=1;j<n;j++){
                Grid[i][j]=Grid[i][j]==0 ? Grid[i-1][j]+Grid[i][j-1] :0;
            }
        }
        return Grid[m-1][n-1];
        
    }
};