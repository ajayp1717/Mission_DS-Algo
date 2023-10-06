class Solution {
public:
    int integerBreak(int n) {
        if(n==2)return 1;
        else if(n==3)return 2;
        int maxi=1;

        while(n>4){
            maxi*=3;
            n-=3;
        }
        maxi*=n;

        return maxi;
        
    }
};