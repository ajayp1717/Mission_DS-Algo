class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n=skill.size();
        long long sum=accumulate(skill.begin(),skill.end(),0);
        long long target=(2*sum)/n;
        if(2*sum%n)return -1;
        sort(skill.begin(),skill.end());
        int i=0,j=n-1;
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