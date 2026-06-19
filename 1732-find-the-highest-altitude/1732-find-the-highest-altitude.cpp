class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans = 0,sum = 0;

        for(const auto &alt : gain) {
            sum += alt ;
            ans = max(ans,sum);
        }
        return ans ;
    }
};