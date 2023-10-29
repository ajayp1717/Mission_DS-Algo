class Solution {
public:
    int minKnightMoves(int x, int y) {
        queue<vector<int>> queue;
        vector<vector<bool>> visited(601, vector<bool>(601));
        queue.push({abs(x), abs(y)});
        int upper_bound = INT_MAX;
        int step = 0;
        visited[x + 300][y + 300] = true;

        while (!queue.empty()) {
            int queue_size = queue.size();

            // When we reach the upper bound, no shorter paths are found.
            if (step == upper_bound) break;

            for (int i = 0; i < queue_size; ++i) {
                vector<int> curr = queue.front();
                queue.pop();

                // Check if we have reached the destination.
                if (curr[0] == 0 && curr[1] == 0) return step;

                // If we reach the immediate neighborhood, update the upper bound.
                if (curr[0] + curr[1] == 2) upper_bound = step + 2;

                for (const auto& coordinate: coordinates) {
                    int next_x = abs(curr[0] + coordinate[0]);
                    int next_y = abs(curr[1] + coordinate[1]);

                    // Marking visited immediately after enqueuing to avoid duplicates.
                    if (!visited[next_x + 300][next_y + 300]) {
                        visited[next_x + 300][next_y + 300] = true;
                        queue.push({next_x, next_y});
                    }
                }
            }
            step++;
        }

        // No shorter paths found. Return the upper_bound.
        return upper_bound;
    }

    // Possible move coordinates for the knight.
    vector<vector<int>> coordinates = {{-1, -2}, {-2, -1}};
};
