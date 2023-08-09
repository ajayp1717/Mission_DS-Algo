class Solution {
public:
    string reverseWords(string s) {
        vector<string> arr;
        int i=0;
        while(i<s.size()){
            string temp="";
            while(s[i]==' ')i++;
            while(s[i]!=' ' && i<s.size()){
                temp+=s[i++];  
            }
            if(!temp.empty())arr.push_back(temp);
        }

        string ans="";
        for(auto x:arr)cout<<x<<" ";
        for(int i=arr.size()-1;i>0;i--){
            ans+=arr[i];
            ans+=' ';
        }
        if(!arr.empty())ans+=arr[0];

        return ans;
    }
};