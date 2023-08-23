class Solution {
public:

    string reorganizeString(string s) {
        
        vector<int>charArr(26,0);
        for(char c:s){
            charArr[c-'a']++;
        }
        int maxi=0;
        int letter=0;
        for(int i=0;i<26;i++){
            if(charArr[i]>maxi){
                maxi=charArr[i];
                letter=i;
            }
        }
        if(maxi>((s.length()+1)/2))return "";

        string ans=s;
        int idx=0;

        while(charArr[letter]!=0){
            ans[idx]=char(letter + 'a');
            idx+=2;
            charArr[letter]--;
        }
       for(int i=0;i<charArr.size();i++){
           
           while(charArr[i]>0){
                if(idx>=s.length()){
                    idx=1;
                }
                ans[idx]=char(i +'a');
                idx+=2;
                charArr[i]--;
           }
       }
        return ans;  
    }
};