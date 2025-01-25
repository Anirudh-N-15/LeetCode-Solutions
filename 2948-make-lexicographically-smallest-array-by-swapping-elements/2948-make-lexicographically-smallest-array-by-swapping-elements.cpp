class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();

        if (n == 0)
            return {};

        // Step 1: Create a vector of pairs where each pair consists of the
        // value and its original index
        vector<pair<int, int>> valueWithIndex(n);
        for (int i = 0; i < n; ++i) {
            valueWithIndex[i] = {nums[i], i};
        }

        // Step 2: Sort the vector based on the values
        sort(valueWithIndex.begin(), valueWithIndex.end());

        // To keep track of the starting index of the current group
        vector<int> result(n);
        int groupStart =0; 

        // Step 3: Process each group of elements that can be sorted together
        for (int i = 0; i < n; ++i) {
            // Check if we are at the end of the group (or end of the array)
            if (i == n - 1 ||
                valueWithIndex[i + 1].first - valueWithIndex[i].first > limit) {

                // Step 4: Gather all indices of the current group
                vector<int> indices;
                for (int j = groupStart; j <= i; ++j) {
                    indices.push_back(valueWithIndex[j].second);
                }

                // Step 5: Sort the indices to assign values in lexicographical
                // order
                sort(indices.begin(), indices.end());

                // Step 6: Place the sorted values back into the result array
                for (int j = 0; j < indices.size(); ++j) {
                    result[indices[j]] = valueWithIndex[groupStart + j].first;
                }

                // Move the groupStart to the next group
                groupStart = i + 1;
            }
        }

        return result;
    }
};