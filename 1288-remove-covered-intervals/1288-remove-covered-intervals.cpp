class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(), [](vector<int> &a,vector<int> &b) {
            if(a[0] != b[0]) return a[0] < b[0] ;
            return a[1] > b[1] ;
        });
        int n = intervals.size() ;
        int ans = n;

        int low = intervals[0][0], high = intervals[0][1] ;

        for(int i =1; i < n; i++) {
            if(intervals[i][0] == low || intervals[i][1] <= high) {
                ans-- ;
            } else {
                low = intervals[i][0] ;
                high = intervals[i][1] ;
            }
        }
        return ans ;
       
    }
};