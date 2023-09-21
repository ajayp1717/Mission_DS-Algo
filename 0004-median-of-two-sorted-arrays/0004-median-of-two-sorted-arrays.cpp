class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(),m=nums2.size();
        vector<int> nums3(n+m);
        int i=0,j=0,k=0;
        while(i<n && j<m){
            if(nums1[i]<nums2[j])
                nums3[k++]=nums1[i++];
            else
                nums3[k++]=nums2[j++];
        }
        while(i<n)
            nums3[k++]=nums1[i++];
        while(j<m)
            nums3[k++]=nums2[j++];
        double ans=0.0;
        int mid=(n+m)/2;
        if((n+m)%2)
            ans=nums3[mid];
        else
            ans=(nums3[mid]+nums3[mid-1])/2.0;
        
        return ans;
    }
};