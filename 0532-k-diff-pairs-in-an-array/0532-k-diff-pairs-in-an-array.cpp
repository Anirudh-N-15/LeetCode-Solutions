class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> umap;
        for (const int& num : nums) {
            umap[num]++;
        }
        int count = 0;
        for (const auto& it : umap) {
            int target = k + it.first;

            if (k > 0) {
                if (umap.find(target) != umap.end()) {
                    count++;
                }
            } else {
                if (umap.find(target) != umap.end()) {
                    if (umap[target] > 1) {
                        count++;
                    }
                }
            }
        }
        return count;
    }
};