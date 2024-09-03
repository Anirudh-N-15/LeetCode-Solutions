class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> store;
        vector<vector<int>> result;
        int index = 1;

        backtrack(store, result, n, k, index);

        return result;
    }

    void backtrack(vector<int>& store, vector<vector<int>>& result, int n,
                   int k, int index) {
        if (store.size() == k) {
            result.push_back(store);
            return;
        }

        for (int i = index; i <= n; ++i) {
            store.push_back(i);
            backtrack(store, result, n, k, i + 1);
            store.pop_back();
        }
    }
};