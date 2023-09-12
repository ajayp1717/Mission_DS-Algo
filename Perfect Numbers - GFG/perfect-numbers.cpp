//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int isPerfectNumber(long long N) {
        // code here
        long long sum=1;
        for(long long i=2;i<=pow(N,0.5);i++){
            if(N%i==0){
                sum+=i;
                // if(sum==N)return 1;
                sum+=(N/i);
            }
            if(sum==N)return 1;
        }
        return 0;
        
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        
        cin>>N;

        Solution ob;
        cout << ob.isPerfectNumber(N) << endl;
    }
    return 0;
}
// } Driver Code Ends