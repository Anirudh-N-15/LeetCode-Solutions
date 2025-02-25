class Solution {
public:
    long int mod = 1e9 + 7;
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        int ans = 0, o = 0, e =1;
        int sum = 0;

        for (int i = 0; i < n; i++) {
            sum += arr[i];
            if (sum % 2 == 0) {
                ans = (ans + o + mod) % mod;
            } else
                ans = (ans + e + mod) % mod;

            if (sum % 2 == 0)
                e++;
            else
                o++;
        }
        return ans;
    }
};