class Solution {
public:
    long long minCost(vector<int>& arr, vector<int>& brr, long long k) {
        long long ans1 = sortedans(arr, brr, k);
        long long ans2 = unsortedans(arr, brr);
        return min(ans1, ans2);
    }

private:
    long long sortedans(vector<int> arr, vector<int> brr, long long k) {
        int n = arr.size();
        std::sort(arr.begin(), arr.end());
        std::sort(brr.begin(), brr.end());
        long long ans = 0;

        for (int i = 0; i < n; ++i) {
            ans += abs(arr[i] - brr[i]);
        }
        return ans + k;
    }

    long long unsortedans(vector<int> arr, vector<int> brr) {
        int n = arr.size();
        long long ans = 0;

        for (int i = 0; i < n; ++i) {
            ans += abs(arr[i] - brr[i]);
        }
        return ans;
    }
};
