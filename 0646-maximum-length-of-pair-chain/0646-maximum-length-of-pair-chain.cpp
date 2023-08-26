class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
    int maxi=0; 
    int cnt=1;
    sort(pairs.begin(),pairs.end(),[](const vector<int>& a,const vector<int>& b){
        return a[1]<b[1];
    });
    for(int i=0;i<pairs.size()-1;i++){
        int chk=pairs[i][1];
        for(int j=i+1;j<pairs.size();j++){
            if(pairs.size()-i<=maxi)return maxi;
            if(chk<pairs[j][0]){
                cnt++;
                chk=pairs[j][1];
            }
        }
        maxi=max(maxi,cnt);
        cnt=1;
    }
    return maxi>1 ? maxi:1;
    }
};