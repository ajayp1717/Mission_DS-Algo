class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
    int maxi=-1001,cnt=0; 
    
    sort(pairs.begin(),pairs.end(),[](const vector<int>& a,const vector<int>& b){
        return a[1]<b[1];
    });
    for(int i=0;i<pairs.size();i++){
        if(pairs[i][0]>maxi){
            cnt++;
            maxi=pairs[i][1];
        }
    }
    return cnt;
    }
};