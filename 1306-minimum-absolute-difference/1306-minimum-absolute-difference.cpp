class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {

        vector<vector<int>>ans;
        sort(arr.begin(),arr.end());
        int minD=1e7;
        for(int i=1;i<arr.size();i++){
            if(arr[i]-arr[i-1]<minD)minD=arr[i]-arr[i-1];
        }
        for(int i=1;i<arr.size();i++){
            vector<int> temp(2,0);
            if(arr[i]-arr[i-1]==minD){
                temp[0]=arr[i-1];
                temp[1]=arr[i];  
                ans.push_back(temp);
            }
        }
        return ans;
    }
};