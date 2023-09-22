class Solution {
public:
    bool isSubsequence(string s, string t) {

        int s1=0,t1=0,cnt=0;
        while(t1<t.length() && s1<s.length()){

            if(t[t1]==s[s1]){
                s1++;t1++;cnt++;
            }
            else{
                t1++;
            }
        }
        return cnt==s.length() ? true:false;
        
    }
};