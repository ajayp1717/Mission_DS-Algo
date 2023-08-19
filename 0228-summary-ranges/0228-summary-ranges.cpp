class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string>ans;
        string temp="";
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            if(temp.empty())temp+=to_string(nums[i]);
            if (i < nums.size() - 1 && nums[i + 1] == nums[i] + 1) {
                cnt++;
                continue;
            } 
            else {
                if (cnt > 0) {
                    temp += "->" + to_string(nums[i]);
                }
                ans.push_back(temp);
                temp = "";
                cnt = 0;
            }
    }
       return ans; 
    }
};