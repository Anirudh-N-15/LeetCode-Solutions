class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n = row.size();
        int swaps = 0;

        for (int i = 0; i < n-1; i++) {
            if (row[i + 1] != (row[i]^1)) {
                for (int j = i + 2; j < n; ++j) {
                    if (row[j] == (row[i] ^ 1)) {
                        swap(row[i + 1], row[j]);
                        swaps++;
                        break;
                    }
                }
            }
        }
        return swaps;
    }
};