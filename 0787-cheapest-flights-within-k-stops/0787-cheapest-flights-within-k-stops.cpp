// using a queue is enough with elements {stops,node,dist}

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {
        vector<vector<pair<int, int>>> adjList(n);
        vector<int> prices(n, 1e9);
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}});
        prices[src] = 0;

        for (int i = 0; i < flights.size(); i++) {
            int u = flights[i][0], v = flights[i][1], price = flights[i][2];
            adjList[u].push_back({v, price});
        }

        while (!q.empty()) {
            auto it = q.front();
            int stops = it.first;
            int node = it.second.first;
            int price = it.second.second;
            q.pop();

            for (auto it : adjList[node]) {
                int currNode = it.first;
                int currPrice = it.second;
                if (price + currPrice < prices[currNode] && stops <= k) {
                    prices[currNode] = price + currPrice;
                    q.push({stops + 1, {currNode, price + currPrice}});
                }
            }
        }
        return prices[dst] == 1e9 ? -1 : prices[dst];
    }
};