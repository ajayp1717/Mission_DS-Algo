class Solution {
public:
    string reverseWords(string s) {
        vector<string> arr;
        int i=0;
        while(i<s.size()){
            string temp="";
            while(s[i]==' ')i++;  //dealing with leading W/S
            while(s[i]!=' ' && i<s.size()){ //dealing with intermediate W/S
                temp+=s[i++];                 
            }
            if(!temp.empty())arr.push_back(temp);  //dealing with trailing W/S
        }

        string ans="";
        for(int i=arr.size()-1;i>=0;i--){
            ans+=arr[i];
            if(i>0)ans+=' ';
        }
        return ans;
    }
    
};