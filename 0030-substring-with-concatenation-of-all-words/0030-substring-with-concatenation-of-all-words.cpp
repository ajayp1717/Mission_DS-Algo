class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> counts;
        for (string word : words)
            counts[word]++;
        
        int n = s.length(), num = words.size(), len = words[0].length();
        int totalLen = num * len;
        vector<int> indexes;
        
        for (int i = 0; i < len; i++) {
            int left = i, count = 0;
            unordered_map<string, int> seen;
            
            for (int j = i; j <= n - len; j += len) {
                string word = s.substr(j, len);
                
                if (counts.find(word) != counts.end()) {
                    seen[word]++;
                    count++;
                    
                    while (seen[word] > counts[word]) {
                        string leftWord = s.substr(left, len);
                        seen[leftWord]--;
                        count--;
                        left += len;
                    }
                    
                    if (count == num) {
                        indexes.push_back(left);
                        string leftWord = s.substr(left, len);
                        seen[leftWord]--;
                        count--;
                        left += len;
                    }
                } else {
                    seen.clear();
                    count = 0;
                    left = j + len;
                }
            }
        }
        
        return indexes;
    }

};