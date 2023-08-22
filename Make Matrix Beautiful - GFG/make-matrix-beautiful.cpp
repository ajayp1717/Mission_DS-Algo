//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find minimum number of operations that are required 
    //to make the matrix beautiful.
    int findMinOpeartion(vector<vector<int> > matrix, int n)
    {
        // code here 
        int maxi=INT_MIN;
        for(int ro=0;ro<n;ro++){
            int temp=0;
            for(int col=0;col<n;col++){
                temp+=matrix[ro][col];
                
            }
            maxi=max(maxi,temp);
        }
        for(int col=0;col<n;col++){
            int temp=0;
            for(int ro=0;ro<n;ro++){
                temp+=matrix[ro][col];
                
            }
            maxi=max(maxi,temp);
        }
        
        int ans=0;
        for(int ro=0;ro<n;ro++){
            int temp=0;
            for(int col=0;col<n;col++){
                temp+=matrix[ro][col];
                
            }
            ans+=maxi-temp;
        }
        return ans;
        
    } 
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > matrix (n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>matrix[i][j];
        Solution ob;
        cout << ob.findMinOpeartion(matrix, n) << endl;
    }
    return 0;
}


// } Driver Code Ends