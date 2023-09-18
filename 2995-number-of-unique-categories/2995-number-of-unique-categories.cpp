/**
 * Definition for a category handler.
 * class CategoryHandler {
 * public:
 *     CategoryHandler(vector<int> categories);
 *     bool haveSameCategory(int a, int b);
 * };
 */
class Solution {
public:
    int numberOfCategories(int n, CategoryHandler* cH) {
        int cnt=n;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <i; j++) {
                if (cH->haveSameCategory(i, j)) {
                    cnt--;
                    break;
                }
            }
        }
        return cnt;
        
    }
};