class Solution {
public:
    int romanToInt(string s) {
        map<string,int>rMap{
            {"M",1000},
            {"CM",900},
            {"D",500},
            {"CD",400},
            {"C",100},
            {"XC",90},
            {"L",50},
            {"XL",40},
            {"X",10},
            {"IX",9},
            {"V",5},
            {"IV",4},
            {"I",1}
        };
        int ans=0,i=0;
        while(i<s.length()){
            string currSym=s.substr(i,1);
            int curr = rMap[currSym];
            int nxt = 0;
            if (i + 1 < s.length()) {
                string nxtSym = s.substr(i + 1, 1);
                nxt = rMap[nxtSym];
            }
            
            if (curr < nxt) {
                ans += (nxt - curr);
                i += 2;
            }
            else {
                ans += curr;
                i += 1;
            }
        }
       
        return ans;
    }
};