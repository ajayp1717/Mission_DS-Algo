class Solution {
public:
    bool feasibleDist(int x1,int y1,int x2,int y2,int r){
        double dist=sqrt(pow((x1-x2),2)+pow((y1-y2),2));
        return dist<=r;
    }
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int>ans;
        for(auto q:queries){
            int cnt=0;
            for(auto p:points){
                if(feasibleDist(q[0], q[1], p[0], p[1], q[2]))cnt++;
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};