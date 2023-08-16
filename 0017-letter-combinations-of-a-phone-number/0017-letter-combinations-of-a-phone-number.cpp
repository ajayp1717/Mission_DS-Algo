class Solution {
public:
   map<char,vector<char>> Mp = {
        {'2', {'a', 'b', 'c'}},
        {'3', {'d', 'e', 'f'}},
        {'4', {'g', 'h', 'i'}},
        {'5', {'j', 'k', 'l'}},
        {'6', {'m', 'n', 'o'}},
        {'7', {'p', 'q', 'r', 's'}},
        {'8', {'t', 'u', 'v'}},
        {'9', {'w', 'x', 'y', 'z'}}
    };
    void helper(int idx,string& temp,string& dig,vector<string> &ans){

        if(idx==dig.size()){
            ans.push_back(temp);
            return;
        }
        char curr=dig[idx];
        vector<char>chars=Mp[curr];

        for(char c:chars){
            temp.push_back(c);
            helper(idx+1,temp,dig,ans);
            temp.pop_back();
        } 
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string combination;
        if(digits.empty())return ans;

        helper(0,combination,digits,ans);

        return ans;
    }
};