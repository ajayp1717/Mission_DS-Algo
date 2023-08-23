class Solution {
public:
    bool helper(vector<vector<char>>& board, string& word, int i, int j, vector<vector<int>>& dirs, vector<vector<bool>>& visited, int k) {
        int n = board.size();
        int m = board[0].size();

        if (k == word.length()) {
            return true; // Found all characters of the word
        }

        if (i < 0 || i >= n || j < 0 || j >= m || visited[i][j] || board[i][j] != word[k]) {
            return false; // Out of bounds or visited or mismatch
        }

        visited[i][j] = true;

        for (auto& dir : dirs) {
            int newi = i + dir[0];
            int newj = j + dir[1];
            if (helper(board, word, newi, newj, dirs, visited, k + 1)) {
                return true;
            }
        }

        visited[i][j] = false; // Backtrack
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0] && helper(board, word, i, j, dirs, visited, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

};