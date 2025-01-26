class Solution {
public:
    int maximumInvitations(vector<int>& nums) {
        int n = nums.size();
        if (n <= 3) return n;

        vector<vector<int>> adj(n);
        vector<int> ind(n, 0), depth(n, 0);

        for (int i = 0; i < n; i++) {
            adj[i].push_back(nums[i]);
            ind[nums[i]]++;
        }

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (ind[i] == 0) q.push(i);
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto next : adj[node]) {
                ind[next]--;
                depth[next] = max(depth[next], depth[node] + 1);
                if (ind[next] == 0) q.push(next);
            }
        }

        int twoChainSum = 0, largestCycle = 0;
        vector<bool> visited(n, false);

        for (int i = 0; i < n; i++) {
            if (ind[i] == 0 || visited[i]) continue;

            int curNode = i, cycleLength = 0;

            while (!visited[curNode]) {
                visited[curNode] = true;
                curNode = nums[curNode];
                cycleLength++;
            }

            if (cycleLength == 2) {
                twoChainSum += depth[i] + depth[nums[i]] + 2;
            } else {
                largestCycle = max(largestCycle, cycleLength);
            }
        }

        return max(twoChainSum, largestCycle);
    }
};