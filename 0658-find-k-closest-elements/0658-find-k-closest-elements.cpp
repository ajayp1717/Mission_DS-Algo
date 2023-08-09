class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {

        int n=arr.size();
        vector<int> ans(k);
        if(x<arr[0]){
            ans.assign(arr.begin(),arr.begin()+k);
            return ans;
        }
        if(x>arr[n-1]){
            ans.assign(arr.begin()+n-k,arr.end());
            return ans;
        }
    //lb to identify the entry point and then explore k closest poz.
        int lb=lower_bound(arr.begin(),arr.end(),x)-arr.begin();

        //Shortening our search space;
        int left=max(0,lb-k);
        int right=min(lb+k-1,n-1);
        
        //windo size-> 'r-l+1'
        while(right-left+1>k){
            if(x-arr[left]<=arr[right]-x) //satisfying given condition
                right--;
            else left++;
        }
        ans.assign(arr.begin()+left,arr.begin()+right+1);
        
        return ans;
    }
};