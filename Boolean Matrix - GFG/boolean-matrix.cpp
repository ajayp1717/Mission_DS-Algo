//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends


class Solution {
public:
    void booleanMatrix(std::vector<std::vector<int>>& matrix) {
        int R = matrix.size();
        int C = matrix[0].size();

        // Arrays to keep track of rows and columns that need to be updated.
        std::vector<bool> rowToUpdate(R, false);
        std::vector<bool> colToUpdate(C, false);

        // Traverse the matrix and mark rows and columns to be updated.
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (matrix[i][j] == 1) {
                    rowToUpdate[i] = true;
                    colToUpdate[j] = true;
                }
            }
        }

        // Update the matrix based on the marked rows and columns.
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (rowToUpdate[i] || colToUpdate[j]) {
                    matrix[i][j] = 1;
                }
            }
        }
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--) 
    {
        int row, col;
        cin>> row>> col;
        vector<vector<int> > matrix(row); 
        for(int i=0; i<row; i++)
        {
            matrix[i].assign(col, 0);
            for( int j=0; j<col; j++)
            {
                cin>>matrix[i][j];
            }
        }
        
        Solution ob;
        ob.booleanMatrix(matrix);


        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}



// } Driver Code Ends