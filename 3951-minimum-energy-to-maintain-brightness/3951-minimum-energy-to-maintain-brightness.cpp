class Solution {
public:
    long long minEnergy(int n, int brightness, vector<vector<int>>& intervals) {
        int bulbs = ceil(brightness/3.0) ;
        cout << bulbs << endl ;
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;

        for(auto interval : intervals) {
            if(ans.empty() || ans.back()[1] < interval[0]) {
                ans.push_back(interval);
            } else {
                ans.back()[1] = max(ans.back()[1], interval[1]) ;
            }
        }
        
        int res = 0;

        for(auto interval : ans) {
            res += interval[1] - interval[0] + 1;
        }
        cout << res << endl ;

        return (long long)bulbs * (long long)res ;
    }
};