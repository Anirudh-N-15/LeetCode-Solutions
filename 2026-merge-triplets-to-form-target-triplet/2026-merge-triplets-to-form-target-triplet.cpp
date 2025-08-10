class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<int> curr = {0, 0, 0};

        for (const auto& triplet : triplets) {
            int u = triplet[0], v = triplet[1], w = triplet[2];

            if (u <= target[0] && v <= target[1] && w <= target[2]) {
                curr[0] = max(curr[0], u);
                curr[1] = max(curr[1], v);
                curr[2] = max(curr[2], w);
            }
            if (curr == target) {
                return true;
            }
        }
        return false;
    }
};