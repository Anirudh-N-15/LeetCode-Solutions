class Solution {
public:
    // state: 0 = FLAT, 1 = LONG, 2 = SHORT
    using ll = long long;
    ll dp[1001][501][3];

    long long memo(vector<int>& prices, int k, int state, int i) {
        int n = prices.size();
        if (i == n) {
            if (state == 0) return 0;
            return -1e18; // invalid unfinished transaction
        }

        if (dp[i][k][state] != -1)
            return dp[i][k][state];

        ll profit = 0;

        // FLAT = no position open
        if (state == 0) {
            // Skip the current position
            profit = max(profit, memo(prices, k, 0, i + 1));

            if (k > 0) {
                // Open position so we buy the stock and start a transaction
                profit = max(profit, memo(prices, k, 1, i + 1) - prices[i]);

                // Open short position
                profit = max(profit, memo(prices, k, 2, i + 1) + prices[i]);
            }
        }
        // LONG = holding a stock
        else if (state == 1) {
            // Hold the stock
            profit = memo(prices, k, 1, i + 1);

            // Sell and then close transaction
            profit = max(profit, memo(prices, k - 1, 0, i + 1) + prices[i]);
        }
        // SHORT = owe a stock(Sold before actually buying)
        else {
            // Hold the stock
            profit = memo(prices, k, 2, i + 1);

            profit = max(profit, memo(prices, k - 1, 0, i + 1) - prices[i]);
        }
        return dp[i][k][state] = profit;
    }

    long long maximumProfit(vector<int>& prices, int k) {
        memset(dp, -1, sizeof(dp));
        return memo(prices, k, 0, 0);
    }
};