class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int lo=0,hi=0;
        int n=s.length();
        int ans=0;
        unordered_map<char,int> Mp;

        for(hi=0;hi<n;hi++){
            if(Mp[s[hi]]>0){
                lo=max(lo,Mp[s[hi]]);
            }
            
            ans=max(ans,hi-lo+1);
            Mp[s[hi]]=hi+1;
        }
        return ans; 
    }
};