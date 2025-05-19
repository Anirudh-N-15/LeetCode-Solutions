class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& nums) {
        int n = nums.size();
        stack<pair<int,int>> st;
        vector<int> ans(n,0);
        for(int i=0;i<n;++i) {
            while(!st.empty() && st.top().first < nums[i]) {
                ans[st.top().second] = i - st.top().second ;
                st.pop();
            }
            st.push({nums[i],i});
        }
        return ans ;
    }
};