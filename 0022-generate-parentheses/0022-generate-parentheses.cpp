class Solution {
public:
    vector<string> ans;
    void helper(int opn,int cls,int n,string temp){
        if(temp.size()==2*n){
            ans.push_back(temp);
            return;
        }
        if(opn<n){
            helper(opn+1,cls,n,temp+'(');
        }
        if(cls<opn)helper(opn,cls+1,n,temp+')');
    }
    vector<string> generateParenthesis(int n) {
         helper(0,0,n,"");
         return ans;
    }
};