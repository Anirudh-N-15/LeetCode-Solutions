// The idea is to use a reverse prefix sum approach for the question.

class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        vector<int> dp = energy;

        for (int i = n - 1; i >= (n - k); i--) {
            int j = i;
            while( j - k >= 0) {
                dp[j - k] += dp[j] ;
                j -= k;
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};