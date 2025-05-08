class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
         int n = moveTime.size(), m = moveTime[0].size();
        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, 0, 0});    
        moveTime[0][0] = 0;

        vector<vector<int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        while (!pq.empty()) {
            auto current = pq.top();
            pq.pop();
            int currTime = current[0];
            int currRow  = current[1];
            int currCol  = current[2];
            if (currTime >= dp[currRow][currCol]) continue;
            if (currRow == n - 1 && currCol == m - 1) return currTime;
            dp[currRow][currCol] = currTime;

            for (auto& dir : directions) {
                int nextRow = currRow + dir[0];
                int nextCol = currCol + dir[1];
                if (nextRow >= 0 && nextRow < n &&
                    nextCol >= 0 && nextCol < m &&
                    dp[nextRow][nextCol] == INT_MAX) {
                    int cost = (currRow + currCol) % 2 + 1; 
                    int start = max(moveTime[nextRow][nextCol], currTime);
                    int nextTime = start + cost;
                    pq.push({nextTime, nextRow, nextCol});
                }
            }
        }
        return -1;
    }
};