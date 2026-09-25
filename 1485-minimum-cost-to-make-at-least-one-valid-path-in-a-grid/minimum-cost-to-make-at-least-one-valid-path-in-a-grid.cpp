    class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> distance(m, vector<int>(n, INT_MAX));
        deque<pair<int, pair<int, int>>> dq;
        distance[0][0] = 0;
        dq.push_front({0, {0, 0}});
        int dr[] = {0, 0, 1, -1};
        int dc[] = {1, -1, 0, 0};
        while (!dq.empty()) {
            auto [cost, pos] = dq.front();
            dq.pop_front();
            int r = pos.first;
            int c = pos.second;
            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                    continue;
                int extraCost = (grid[r][c] == i + 1) ? 0 : 1;
                if (distance[r][c] + extraCost < distance[nr][nc]) {
                    distance[nr][nc] = distance[r][c] + extraCost;
                    if (extraCost == 0)
                        dq.push_front({distance[nr][nc], {nr, nc}});
                    else
                        dq.push_back({distance[nr][nc], {nr, nc}});
                }
            }
        }
        return distance[m - 1][n - 1];
    }
};