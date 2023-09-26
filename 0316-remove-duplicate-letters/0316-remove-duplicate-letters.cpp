class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, bool> used;
        vector<int> lastOccur(26, -1);
        stack<char> St;

        string ans = "";

        for (int i = 0; i < s.length(); i++) {
            lastOccur[s[i] - 'a'] = i;
        }

        for (int i = 0; i < s.length(); i++) {
            char curr = s[i];
            if (used[curr]) continue;

            while (!St.empty() && curr < St.top() && i < lastOccur[St.top() - 'a']) {
                used[St.top()] = false;
                St.pop();
            }
            St.push(curr);
            used[curr] = true;
        }

        while (!St.empty()) {
            ans = St.top() + ans;
            St.pop();
        }

        return ans;
    }

};