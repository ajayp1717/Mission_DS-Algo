class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        if (query_row == 0) {
            // Special case for the first row, no overflow.
            return min(1.0, (double)(poured));
        }

        vector<vector<double>> tower(query_row + 1, vector<double>(query_row + 1, 0.0));
        tower[0][0] = (double)(poured);

        for (int row = 0; row < query_row; ++row) {
            for (int glass = 0; glass <= row; ++glass) {
                double overflow = (tower[row][glass] - 1.0) / 2.0;
                if (overflow > 0) {
                    tower[row + 1][glass] += overflow;
                    tower[row + 1][glass + 1] += overflow;
                }
            }
        }

        return min(1.0, tower[query_row][query_glass]);
    }
};