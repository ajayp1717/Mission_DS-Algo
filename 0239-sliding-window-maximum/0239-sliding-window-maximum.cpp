class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        deque<int>decDeq;   //monotonic decreasing deque
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            //remove elements that r no longer part of curr window
            while(!decDeq.empty() && decDeq.front()<i-k+1){
                decDeq.pop_front();
            }
            
            while(!decDeq.empty() && nums[i]>nums[decDeq.back()]){
                decDeq.pop_back();
            }
            
            decDeq.push_back(i);

            //add maximum to the ans for curr window
            if(i>=k-1){
                ans.push_back(nums[decDeq.front()]);
            }
        }
        return ans;
    }
};