class Solution {
public:
    void solve(vector<vector<int>>& ans, vector<int>& comb,
               vector<int>& candidates, int target, int index) {

        if (target == 0) {
            ans.push_back(comb);
            return;
        }
        

        for (int i = index; i < candidates.size(); i++) {
            if (i > index && candidates[i] == candidates[i - 1]) {
                continue;
            }
            if (candidates[i] > target)
                break;

            comb.push_back(candidates[i]);
            solve(ans, comb, candidates, target - candidates[i], i + 1);
            comb.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> comb;
        sort(candidates.begin(), candidates.end());

        solve(ans, comb, candidates, target, 0);
        return ans;
    }
};