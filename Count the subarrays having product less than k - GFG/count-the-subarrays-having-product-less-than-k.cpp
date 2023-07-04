//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends


class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        
        long long prevProd=1,cnt=0;
        for(int i=0;i<a.size();i++){
            
            for(int j=i;j<a.size();j++){
                
                prevProd*=a[j];
                
                // cout<<prevProd<<" ";
                if(prevProd<k){
                    cnt++;
                    if(j==a.size()-1)prevProd=1;
                }
                else{
                    prevProd=1;
                    break;
                }
            }
        }
        // cout<<endl;
        return cnt;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        long long int k;
        cin >> n >> k;
        vector<int> arr(n);
        for (i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.countSubArrayProductLessThanK(arr, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends