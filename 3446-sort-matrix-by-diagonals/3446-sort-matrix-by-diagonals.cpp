class Solution {
public:
    vector<int> sorted(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        return nums;
    }

    vector<int> ascSort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums;
    }

    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        for (int i = 0; i < n; i++) {
            vector<int> nums;
            int r = i, c = 0;
            while (r < n && c < n) {
                nums.push_back(grid[r][c]);
                r++;
                c++;
            }
            nums = sorted(nums); 
            r = i, c = 0;
            for (int k = 0; k < nums.size(); k++) {
                grid[r][c] = nums[k];
                r++;
                c++;
            }
        }

        for (int j = 1; j < n; j++) {
            vector<int> nums;
            int r = 0, c = j;
            while (r < n && c < n) {
                nums.push_back(grid[r][c]);
                r++;
                c++;
            }
            nums = ascSort(nums); 
            r = 0, c = j;
            for (int k = 0; k < nums.size(); k++) {
                grid[r][c] = nums[k];
                r++;
                c++;
            }
        }

        return grid;
    }
};
