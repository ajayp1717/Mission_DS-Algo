class Solution {
public:

    string convertToTitle(int cN) {
        string ans="";
        while(cN){
            cN--;   //adjust to 1-based indexing
            int temp=cN%26;
            ans=char('A'+temp)+ans;
            cN/=26;
        }
        return ans;
        
        
    }
};