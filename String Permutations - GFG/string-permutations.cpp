//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    void permute(string S,string temp,vector<string> &ans,int pres[]){
        int n=S.size();
        if(temp.size()==n){
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<S.size();i++){
            if(!pres[i]){
                temp+=S[i];
                pres[i]=1;
                permute(S,temp,ans,pres);
                pres[i]=0;
                temp.pop_back();
            }
        }  
    }
    
    vector<string> permutation(string S)
    {
        //Your code here 
        vector<string>ans;
        string temp="";
        int pres[S.size()];
        
        for(int i=0;i<S.size();i++){
            pres[i]=0;
        }  
        permute(S,temp,ans,pres);
        sort(ans.begin(),ans.end());
        
        return ans; 
    }
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends