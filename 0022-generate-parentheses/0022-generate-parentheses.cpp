class Solution {
public:
    void helper(int opn,int cls,int n,vector<string>& ans,string temp){
        if(temp.size()==2*n){
            ans.push_back(temp);
            return;
        }
        if(opn<n){
            helper(opn+1,cls,n,ans,temp+'(');
        }
        if(cls<opn)helper(opn,cls+1,n,ans,temp+')');
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
         helper(0,0,n,ans,"");
         return ans;
    }
};