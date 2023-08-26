//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
        if(k>s.length())return -1;
        unordered_map<char,int>Mp;
        int l=0,r=0;
        int maxi=0;
        for(r=0;r<s.length();r++){
            Mp[s[r]]++;
            
            while(Mp.size()>k){
                Mp[s[l]]--;
                if(Mp[s[l]]==0)
                    Mp.erase(s[l]);
                
                l++;
            }
            maxi=max(maxi,r-l+1);
        }
        return maxi;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends