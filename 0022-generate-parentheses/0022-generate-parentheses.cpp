class Solution {
public:
    vector<string> ans;
    bool isValid(string chk){
        int lCount=0;
        for(char x:chk){
            if(x=='(')lCount++;
            else lCount--;

            if(lCount<0)return false;
        }
        return lCount==0;

    }
    void helper(int opn,int cls,int n,string temp){
        if(temp.size()==2*n){
            if(isValid(temp))ans.push_back(temp);
            return;
        }
        if(opn<n){
            helper(opn+1,cls,n,temp+'(');
        }
        if(cls<n)helper(opn,cls+1,n,temp+')');
    }
    vector<string> generateParenthesis(int n) {
         helper(0,0,n,"");
         return ans;
    }
};