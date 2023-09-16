class Solution {
public:
    vector<vector<int>> ways{{1,0},{0,1},{0,-1},{-1,0}};

    int minimumEffortPath(vector<vector<int>>& heights) {
        int lo=0,hi=10e6;
        int res=hi;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(canReach(heights,mid)){
                res=min(res,mid);
                hi=mid-1;
            }
            else lo=mid+1;
        }
        return res;  
    }
    bool canReach(vector<vector<int>>& heights,int mid){

        int n=heights.size(),m=heights[0].size();
        queue<pair<int,int>>q;
        vector<vector<bool>>vis(n,vector<bool>(m,0));
        q.push({0,0});
        vis[0][0]=1;
        while(!q.empty()){
            auto cell=q.front();
            q.pop();
            int x=cell.first,y=cell.second;
            if(x==n-1 && y==m-1)return true;

            for(auto w:ways){
                int n_x=x+w[0],n_y=y+w[1];
                if(validCell(n_x,n_y,n,m) && !vis[n_x][n_y]){
                    int currDiff=abs(heights[n_x][n_y]-heights[x][y]);
                    if(currDiff<=mid){
                        vis[n_x][n_y]=1;
                        q.push({n_x,n_y});
                    }
                }      
            }
        }
        return false;

    }
    bool validCell(int x,int y,int row,int col){
        return x>=0 && x<row && y>=0 && y<col;
    }
};