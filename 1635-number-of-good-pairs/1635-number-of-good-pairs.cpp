class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {

        unordered_map<int,int> Mp;

        for(auto x:nums){
            Mp[x]++;
        }

        int sum=0;
        for(auto x:Mp){

            sum+=x.second*(x.second-1)/2;
            
        }
        return sum;
        
    }
};