class Solution {
public:
    char findTheDifference(string s, string t) {
       unordered_map<char,int>Mp;
       for(char c:s)Mp[c]++;

       for(char ch:t){
           if(Mp[ch]==0)Mp.erase(ch);
           if(Mp.find(ch)!=Mp.end())Mp[ch]--;
           else return ch;
       }

       return '#';
    }
};