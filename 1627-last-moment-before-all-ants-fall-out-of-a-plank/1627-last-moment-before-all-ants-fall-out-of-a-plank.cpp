class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        
        int maxLeft = left.empty() ? 0 : *max_element(left.begin(), left.end());
        
        int minRight = right.empty() ? n : *min_element(right.begin(), right.end());
        
        // The one among above two would be the last one to off of the plank among all.
        return max(maxLeft, n - minRight);
    }
};