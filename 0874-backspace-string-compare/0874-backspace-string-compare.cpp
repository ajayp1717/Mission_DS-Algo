class Solution {
public:
    string erase(string str) {
        int i = str.length() - 1;
        string temp = "";
        int cnt = 0;
        while (i >= 0) {
            if (str[i] == '#') {
                while (i >= 0 && str[i] == '#') {
                    cnt++;
                    i--;
                }
                while (i >= 0 && cnt > 0) {
                    if (str[i] != '#') {
                        cnt--;
                    } else {
                        cnt++;
                    }
                    i--;
                }
            } else {
                temp = str[i] + temp;
                i--;
            }
        }
        return temp;
    }

    bool backspaceCompare(string s, string t) {
        if(s==t)return true;

        string s1=erase(s);
        string t1=erase(t);
        return s1==t1;
        
        
    }
};