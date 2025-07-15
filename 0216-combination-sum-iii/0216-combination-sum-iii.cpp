class Solution {
public:
    void solve(set<vector<int>>& res,vector<int> nums,int index, int k, int n) {
        if(n == 0 && k == 0) {
            res.insert(nums);
            return ;
        }

        if(nums.empty()) {
            for(int i=1;i<=9;i++) {
                if(i <= n) {
                    nums.push_back(i);
                    solve(res,nums,index+1,k-1,n - i);
                    nums.pop_back();
                }
            }
        } else {
            for(int i=nums.back();i<=9;i++) {
                if(i <= n && i!= nums.back()) {
                    nums.push_back(i);
                    solve(res,nums,index+1,k-1,n - i);
                    nums.pop_back();
                }
            }
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        set<vector<int>> res ;
        vector<int> nums ;

        solve(res,nums,0,k,n);

        vector<vector<int>> ans(res.begin(),res.end()); 
        return ans ;
    }
};