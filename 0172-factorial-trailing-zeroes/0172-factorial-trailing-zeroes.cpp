class Solution {
public:
    int trailingZeroes(int n) {
        if(n<5)return 0;
        long long ans=0;
        while(n>=5){
            ans+=n/5ll;
            n/=5;
        }
        return ans;

        
    }
};