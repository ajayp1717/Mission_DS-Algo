//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to find the smallest positive number missing from the array.
    int missingNumber(int arr[], int n) 
    { 
        // Your code here
       
        for(int i=0;i<n;i++){
            int CI=arr[i]-1;
           while(arr[i]>0 && arr[i]<=n && arr[i]!=arr[CI]){
                swap(arr[CI],arr[i]);
                CI=arr[i]-1;
            }
        }
        
        for(int k=0;k<n;k++){
            if(arr[k]!=k+1)return k+1;
            
        }
        return n+1;
        
    } 
};

//{ Driver Code Starts.

int missingNumber(int arr[], int n);

int main() { 
    
    //taking testcases
    int t;
    cin>>t;
    while(t--){
        
        //input number n
        int n;
        cin>>n;
        int arr[n];
        
        //adding elements to the array
        for(int i=0; i<n; i++)cin>>arr[i];
        
        Solution ob;
        //calling missingNumber()
        cout<<ob.missingNumber(arr, n)<<endl;
    }
    return 0; 
} 
// } Driver Code Ends