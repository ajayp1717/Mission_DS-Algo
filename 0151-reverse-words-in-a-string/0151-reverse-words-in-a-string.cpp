class Solution {
public:
    string reverseWords(string s) {
        vector<string> arr;
        stringstream ss(s);
        string word;

        while(ss >>word)arr.push_back(word);

        // while(i<s.size()){
        //     string temp="";
        //     while(s[i]==' ')i++;
        //     while(s[i]!=' ' && i<s.size()){
        //         temp+=s[i++];  
        //     }
        //     if(!temp.empty())arr.push_back(temp);
        // }


        string ans="";
        for(int i=arr.size()-1;i>=0;i--){
            ans+=arr[i];
            if(i>0)ans+=' ';
        }
        return ans;
    }
};