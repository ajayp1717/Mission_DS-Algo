class Solution {
public:
    string reverseWords(string s) {
        string temp="";
        string ans="";
        for(int i=s.length()-1;i>=0;i--){
            if(s[i]==' '){
                ans=' '+temp+ans;
                temp="";
            }
            else    temp+=s[i];
        }
        if(!temp.empty()){
            ans=temp+ans;
        }
        return ans;
    }
};