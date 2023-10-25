class Solution {
public:
    int kthGrammar(int n, int k) {
        if (n == 1) {
            return 0;
        }
        
        int mid = (1 << (n - 2)); // Length of each half in the (n-1)th row
        
        if (k <= mid) {
            // The kth character is in the first half of the (n-1)th row
            return kthGrammar(n - 1, k);
        } else {
            // The kth character is in the second half of the (n-1)th row
            return 1 - kthGrammar(n - 1, k - mid);
        }
    }

    
};

// 0
// 01
// 0110
// 01101001
// 0110100110010110
// 01101001100101101001011001101001