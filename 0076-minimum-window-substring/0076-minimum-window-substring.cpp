class Solution {
public:
    string minWindow(string s, string t) {
        // Check if either string is empty
        if (s.length() == 0 || t.length() == 0) {
            return "";
        }
        unordered_map<char, int> tMp;
        for (char c : t) {
            tMp[c]++;
        }

        // Number of distinct characters required for forming a valid window
        int required = tMp.size();

        // Create a vector to store filtered characters from string s
        vector<pair<int, char>> filteredS;
        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            if (tMp.find(c) != tMp.end()) {
                filteredS.push_back(make_pair(i, c));
            }
        }

        //formed-> cntr for distinct chars formed
        int l = 0, r = 0, formed = 0;
        unordered_map<char,int>window;
        
        //array to store (length, start, end) of min window
        int ans[3] = {-1, 0, 0};

        // Sliding window algorithm
        while (r < filteredS.size()) {
            char c = filteredS[r].second;
            window[c]++;

            if (tMp.find(c) != tMp.end() && window[c] == tMp[c]) {
                formed++;
            }

            // Try to contract the window until a desirable state is reached
            while (l <= r && formed == required) {
                c = filteredS[l].second;

                int end = filteredS[r].first;
                int start = filteredS[l].first;
                
                // Update the result if the current window is smaller than the previous one
                if (ans[0] == -1 || end - start + 1 < ans[0]) {
                    ans[0] = end - start + 1;
                    ans[1] = start;
                    ans[2] = end;
                }

                window[c]--;
                
                // If a character count becomes insufficient, reduce the formed count
                if (tMp.find(c) != tMp.end() && window[c] < tMp[c]) {
                    formed--;
                }
                l++;
            }
            r++;
        }
        return ans[0] == -1 ? "" : s.substr(ans[1], ans[0]); 
    }
};