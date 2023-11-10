class Solution {
public:
    int countHomogenous(string s) {

        int streak=0;
        long MOD=1e9+7;
        int ans=0;
        for(int i=0;i<s.length();i++){
            if(i==0 || s[i]==s[i-1]){
                streak++;
            }
            else{
                streak=1;
            }
            ans=(ans+streak)%MOD;
        }
        return ans;
    }
};