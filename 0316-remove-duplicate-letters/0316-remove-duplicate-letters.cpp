class Solution {
public:
    string removeDuplicateLetters(string s) {

        // storing last occurrence index of each character
        vector<int> lastOcc(26, -1); 
        vector<bool> used(26, false); 
        string res = "";

        for (int i = 0; i < s.length(); i++) {
            lastOcc[s[i] - 'a'] = i;
        }

        for (int i = 0; i < s.length(); i++) {
            char curr = s[i];

            if (used[curr - 'a']) {
                continue;
            }
        //removing chars from res if they are -gt curr and they appear later in string
            while (!res.empty() && curr < res.back() && i < lastOcc[res.back() - 'a']) {
                used[res.back() - 'a'] = false;
                res.pop_back();
            }
            res += curr;
            used[curr - 'a'] = true;
        }
        return res;
    }

};