class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n=arr.size();
        if(n<2)return arr[0];
        if(k==1)return max(arr[0],arr[1]);
        if(k>=arr.size()) return *max_element(arr.begin(),arr.end());

        int i=0,j=1;
        int cnt=0;
        while(i<n && j<n){
            if(cnt==k)return arr[i];
            if(arr[i]>arr[j]){
                j++;
                cnt++;
            }
            else{
                i=j;
                j++;
                cnt=1;
            }
        }
        return arr[i];
    }
};

