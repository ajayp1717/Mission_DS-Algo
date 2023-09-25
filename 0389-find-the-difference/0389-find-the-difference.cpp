class Solution {
public:
    char findTheDifference(string s, string t) {
       char ch=0;
       for( auto c:s)ch^=c;
       for(auto c1:t)ch^=c1;

       return ch;
    }
};