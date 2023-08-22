class Solution {
public:

    string convertToTitle(int cN) {
        int temp=0;
        string ans="";
        while(cN){
            cN--;   //adjust to 1-based indexing
            temp=cN%26;
            ans=char('A'+temp)+ans;
            cN/=26;
        }
        return ans;
        
        
    }
};