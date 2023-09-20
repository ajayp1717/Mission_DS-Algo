class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n=skill.size();
        sort(skill.begin(),skill.end());
        int i=0,j=n-1;
        int target=skill[i]+skill[j];
        long long ans=0;
        while(i<j){
            if(skill[i]+skill[j]==target){
                ans+=(skill[i]*skill[j]);
                i++,j--;
            }
            else return -1;
                
        }
        return ans; 
    }
};