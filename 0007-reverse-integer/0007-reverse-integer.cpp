class Solution {
public:
    
    int reverseNum(int n) {
        int ans = 0;
        while (n != 0) {
            // Check for overflow before updating ans
            if (ans > INT_MAX / 10 || ans < INT_MIN / 10) return 0;
            ans = ans * 10 + n % 10;
            n /= 10;
        }
        return ans;
    }

    int reverse(int x) {
        int flagNeg = (x < 0);
        int rev = reverseNum(abs(x));
        if (rev > INT_MAX || rev < INT_MIN) return 0;
        return flagNeg ? -rev : rev;
    }
};