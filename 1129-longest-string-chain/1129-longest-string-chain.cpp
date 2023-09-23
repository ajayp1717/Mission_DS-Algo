class Solution {
public:
    int longestStrChain(vector<string>& words) {
        
        int ans = 0; 
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.length() < b.length();
        });

        unordered_map<string,int>Mp;
        for(auto word: words){
            int currMaxi=1;
            for(int i=0;i<word.length();i++){
                
                string pred=word.substr(0,i)+word.substr(i+1);
                if(Mp.count(pred)){
                    currMaxi=max(currMaxi,Mp[pred]+1);
                }

            }
            Mp[word]=currMaxi;
            ans=max(ans,currMaxi);
        }
        return ans;
    }
};