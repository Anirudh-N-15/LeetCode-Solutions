class Solution {
public:
    int solve(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size(), m = waterStartTime.size();
        int ans = INT_MAX;

        for( int i = 0; i < n; i++) {
            ans = min(ans,landStartTime[i] + landDuration[i]);
        }

        int fin = INT_MAX ;

        for(int i = 0 ; i < m; i++){ 
            fin = min(max(ans,waterStartTime[i])+ waterDuration[i], fin);
        }
        return fin ;
    }

    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int minLand = solve(landStartTime, landDuration, waterStartTime, waterDuration);
        int minWater = solve(waterStartTime, waterDuration,landStartTime, landDuration);

        return min(minLand,minWater);
    }
};