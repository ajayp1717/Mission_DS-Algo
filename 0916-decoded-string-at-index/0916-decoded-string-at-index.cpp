class Solution {
public:
    string decodeAtIndex(string s, int k) {
        string temp="";
        long long expLength=0;
        for(auto x:s){
            if(isdigit(x))
                expLength*=int(x-'0');
            else expLength++; 
        }
        for(int i=s.length()-1;i>=0;i--){
            char c=s[i];
            if(isdigit(c)){
                int dig=c-'0';
                expLength/=dig;
                k%=expLength;
            }
            else{
                if(k==0 || k==expLength){
                    return string(1,c);
                }
                expLength--;
            }
        }
        return " ";     
    }
};