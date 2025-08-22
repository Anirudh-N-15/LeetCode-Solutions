//So there are 3 cases over here. Linear search solution is enough over here.

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        vector<vector<int>> ans ;
        int i=0;

        //Case 1:When we can insert the intervals directly into ans
        while(i < n && intervals[i][1] < newInterval[0]) {
            ans.push_back(intervals[i]);
            i++ ;
        }

        //Case 2:When merging has to be done.
        while(i < n && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0],intervals[i][0]);
            newInterval[1] = max(newInterval[1],intervals[i][1]);
            i++ ;
        }
        ans.push_back(newInterval);
        //Case 3: All merging is over and we can just push into ans
        while(i < n) {
            ans.push_back(intervals[i]);
            i++ ;
        }
        return ans ;
    }
};