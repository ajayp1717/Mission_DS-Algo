class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int sum=0;
        sort(costs.begin(),costs.end(),[](auto a,auto b){
            return a[0]-a[1] < b[0]-b[1];
        });
        int n= costs.size()/2;
       
       for(int i=0;i<n;i++){
           sum+= costs[i][0]+costs[i+n][1];
       }
        return sum;
    }
};