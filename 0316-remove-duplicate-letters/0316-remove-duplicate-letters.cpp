class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> lastOccurrence(26, -1); // To store the last occurrence index of each character
        vector<bool> used(26, false); // To keep track of characters already used in the result
        string result = "";

        // Populate lastOccurrence with the last index of each character in s
        for (int i = 0; i < s.length(); i++) {
            lastOccurrence[s[i] - 'a'] = i;
        }
        for (int i = 0; i < s.length(); i++) {
            char currentChar = s[i];

            // Skip characters that have already been used
            if (used[currentChar - 'a']) {
                continue;
            }
            // Keep removing characters from the result if they are greater than the current character
            while (!result.empty() && currentChar < result.back() && i < lastOccurrence[result.back() - 'a']) {
                used[result.back() - 'a'] = false;
                result.pop_back();
            }
            result += currentChar;
            used[currentChar - 'a'] = true;
        }
        return result;
    }

};